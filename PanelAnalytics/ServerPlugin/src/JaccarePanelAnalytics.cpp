#include <Soca/Com/SodaClient.h>
#include "JaccarePanelAnalytics.h"

#include <QtCore/QDateTime>
MP new_tracker_completed(const MP &panel ) {
      MP TFC = MP::new_obj( "TrackerFaceCompleted" );
      QTime date =  QTime::currentTime();
      TFC[ "Created_at" ]       = date.toString();;
      TFC[ "Age" ]              = 20;
      TFC[ "Gender" ]           = 0;
      TFC[ "ID" ]               = 0;
      TFC[ "Xpos" ]             = 1.0;
      TFC[ "Ypos" ]             = 170;
      
      TFC[ "Attention" ]        = 20;
      TFC[ "BeginTrackTime" ]   = 0;
      TFC[ "CamerID" ]          = 0;
      TFC[ "EndTrackTime" ]     = 1.0;
      TFC[ "PanelID" ]          = panel[ "ID" ];   
      
      return TFC;
}


bool JaccarePanelAnalytics::direct_run( MP mp ) {
    MP ch = mp[ "tracker_completed" ]; //on recupere le tracker
    for( int i = 0; i < ch.size(); ++i ) {
        MP panel = ch[ i ];
        int id = panel[ "ID" ];
        if(id == -1){
            //         qDebug() << panel;
//             qDebug() << panel[ "ID" ];
            int mp_server_id = panel.get_server_id();
            panel[ "ID" ] = mp_server_id;
            QString name;
            QTextStream(&name) << "panel_" << mp_server_id ;
            panel[ "_name" ] = name;
        }
    }
    add_message( mp, ET_Info, "JaccarePanelItem -> OK" );
//     qDebug() << "JaccarePanelItem just finish";
}


bool JaccarePanelAnalytics::run( MP mp ) {
    add_message( mp, ET_Info, "JaccarePanelItem -> OK" );
    qDebug() << "JaccarePanelItem just finish";
}
