#include <Soca/Com/SodaClient.h>
#include "JaccarePanelUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;
  
    //id du model à traiter   
    sc.reg_type( "JaccarePanelManagerItem" );
    
    
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        quint64 req = mp[ "_req_date" ];
        quint64 rep = mp[ "_rep_date" ];
//         qDebug() << req << rep;
        if ( req <= rep )
            continue;
        
        qDebug() << "###############   launch JaccarePanelManagerItem ###############" ;
        qDebug() << mp.get_server_id();
        JaccarePanelUpdater updater;
        updater.sc = &sc;
        updater.direct_run( mp );
        mp[ "_rep_date" ] = req;
        mp.flush();
    }
}
