#include <Soca/Com/SodaClient.h>
#include "JaccarePanelUpdater.h"

bool JaccarePanelUpdater::direct_run( MP mp ) {
    MP ch = mp[ "_children" ]; //on recupere l'image
//     qDebug() << mp;
    for( int i = 0; i < ch.size(); ++i ) {
        MP panel = ch[ i ];
        int id = panel[ "ID" ];
        if(id == -1){
            //         qDebug() << panel;
            qDebug() << panel[ "ID" ];
            int mp_server_id = panel.get_server_id();
            panel[ "ID" ] = mp_server_id;
            QString name;
            QTextStream(&name) << "panel_" << mp_server_id ;
            panel[ "_name" ] = name;
        }
    }
    add_message( mp, ET_Info, "JaccarePanelUpdater -> OK" );
    qDebug() << "JaccarePanelUpdater just finish";
}


bool JaccarePanelUpdater::run( MP mp ) {
    add_message( mp, ET_Info, "JaccarePanelUpdater -> OK" );
    qDebug() << "JaccarePanelUpdater just finish";
}
