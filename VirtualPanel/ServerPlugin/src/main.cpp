#include <QtCore/QTimer>
#include <QtCore/QDateTime>
#include <Soca/Com/SodaClient.h>
#include "VirtualJaccarePanelUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;
  
    // id du panel à traiter 
//     quint64 model_id = 29112560;        // id du panel courant
    quint64 model_id = atoi(argv[1]);           // id du panel courant
    MP panel_id = sc.load_ptr(model_id);        // ouverture du PanelFileItem
    qDebug() << panel_id;
    
    // récupération du fichier contenant les données du panel
    MP mod_file = panel_id[ "_file" ];
    qDebug() << mod_file;
    quint64 ptr = mod_file[ "_ptr" ];
    QString name = mod_file[ "name" ];
    qDebug() << name;
    
    
    MP panel = sc.load_ptr( ptr );
    qDebug() << panel;
    
    if (panel.ok()){
        sc.reg_model( panel_id );               // observation du panel_id
        sc.reg_model( panel );                  // observation du panel
        
        QTimer *timer = new QTimer();
        QObject::connect(timer, SIGNAL(timeout()), &sc, SLOT(force_callback( )));
        timer->start(3000);
        
        
        // attente
        while ( SodaClient::Event event = sc.event() ) {
            quint64 active = panel_id[ "active" ]; 
            if (active == false){
                //qDebug() << "envoie des données désactivé" ; 
            }else{
                QTime date =  QTime::currentTime();
//                 qDebug() << event.event_num;    
                quint64 req = panel[ "_req_date" ];
                quint64 rep = panel[ "_rep_date" ];
//                 qDebug() << req << rep;
                if ( req > rep ){
                    qDebug() << "###############   launch Panel info updater   ###############" ;
        //             VirtualJaccarePanelUpdater updater;
        //             updater.sc = &sc;
        //             updater.direct_run( mp );
                }
                else if (event.event_num == 1){
                    //qDebug() << "###############   add info   ###############" ;
        //             qDebug() <<  mod[ "DateTime" ];
        //             mod[ "DateTime" ] = date.toString();
        //             qDebug() <<  mod[ "DateTime" ];
                    VirtualJaccarePanelUpdater updater;
                    updater.sc = &sc;
                    updater.push_tracker( panel );
                }

                panel[ "_rep_date" ] = req;
                panel.flush();   
            }
        }
    }
}
