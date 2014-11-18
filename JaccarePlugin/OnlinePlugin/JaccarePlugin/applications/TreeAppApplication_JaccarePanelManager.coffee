class TreeAppApplication_JaccarePanel extends TreeAppApplication
    constructor: ->
        super()
        
        @mesher = ''
        @name = 'Connected panel'
        @powered_with    = 'Jaccare'

            
        @actions.push
            ico: "img/Panel_manager.png"
            siz: 1
            txt: "Connected panel"
            fun: ( evt, app ) =>
                app.undo_manager.snapshot()
                @panel_manager = @add_item_depending_selected_tree app.data, JaccarePanelManagerItem

        
            