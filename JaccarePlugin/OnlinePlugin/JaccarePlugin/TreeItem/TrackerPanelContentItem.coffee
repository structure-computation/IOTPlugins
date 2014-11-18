#
class TrackerPanelContentItem extends TreeItem
    constructor: ( panelId ) ->
        super()
        
        @add_attr
            Action      : ""
            DateTime    : new Date  
            Faces       : new Lst            #list of TrackerFaceRealTime
            ID          : -1
            PanelID     : panelId
            Title       : ""             
