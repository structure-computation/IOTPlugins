#


class TrackerFaceRealTime extends TrackerFaceBase
    constructor: (  ) ->
        super()
        
        @add_attr
            AngleYaw            : 1.0
            bAttentionNow       : true
            GenderConfidence    : 1.0
