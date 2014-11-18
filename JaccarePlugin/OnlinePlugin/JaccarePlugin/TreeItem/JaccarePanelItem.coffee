#
class JaccarePanelItem extends TreeItem_Automatic
    constructor: ( _panel_id ) ->
        super()
        
        @_name.set _panel_id.name
        @_viewable.set false
        
        @add_attr
            panel_id    : _panel_id
            ID          : _panel_id.ID
            DateTime    : ""              #date de mise en service
            pos         : []                    #position géographique du panneau
            
        @add_attr
            tracker_content     : new TrackerPanelContentItem @ID
            tracker_completed   : new Lst
            
