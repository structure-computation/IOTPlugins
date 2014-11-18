#include <Soca/Com/SodaClient.h>
#include "JaccarePanelAnalytics.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;
  
    //id du model à traiter   
//     sc.reg_type( "JaccarePanelItem" );
    sc.reg_type( "TrackerFaceCompleted" );
    
    quint64 model_id = 14510336 ;                      // id du panelManager
    MP panel_manager_id = sc.load_ptr(model_id);        // ouverture du panelManager
    
    MP testlst = panel_manager_id[ "_tracker_completed" ];
    
    Lst test;
    test._data.resize(10);
    
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
//         quint64 req = mp[ "_req_date" ];
//         quint64 rep = mp[ "_rep_date" ];
//         qDebug() << req << rep;
//         if ( req <= rep )
//             continue;
        qDebug() << mp["PanelID"] << " ; " << mp["Created_at"];
        
        test._data.erase(test._data.begin());
        test.push(mp.model());
        
        MP testls(&test);
        qDebug() << testls[0] ;
//         qDebug() << testls[0] << " ; " << testls[9];
        
//         testlst.reassign(testls);
        panel_manager_id[ "_tracker_completed" ].clear();
        for( int j = 0; j < testls.size(); ++j ) {
            panel_manager_id[ "_tracker_completed" ] << testls[j];
        }
//         qDebug() << "----" << testlst[0];
        qDebug() << "----" << panel_manager_id[ "tracker_completed" ];
        
        
        panel_manager_id.flush();
        
//         qDebug() << panel_manager_id;
        
//         qDebug() << testls[0] << " ; " << testls[9];
        
    }
}
