#


class TrackerFaceCompleted extends TrackerFaceBase
    constructor: (  ) ->
        super()
        
        @add_attr
            Attention         : 20
            BeginTrackTime    : 0
            CamerID           : 0
            EndTrackTime      : 1.0
            PanelID           : 1.0

