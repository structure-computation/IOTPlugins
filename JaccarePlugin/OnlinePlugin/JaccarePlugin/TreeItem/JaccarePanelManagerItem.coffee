#
class JaccarePanelManagerItem extends TreeItem_Automatic
    constructor: ( name = "panel_manager" ) ->
        super()
        
        # default values
        @_name.set name
        @_viewable.set false

        @add_attr
            _tracker_completed   : new Lst
    

    accept_child: ( ch ) ->
        ch instanceof JaccarePanelFileItem

    display_suppl_context_actions: ( context_action )  ->
        context_action.push 
            txt: "Add a new panel"
            ico: "img/add.png"
            fun: ( evt, app ) =>
                instance = this
                panel_id = new JaccarePanelFileItem
                panel = new JaccarePanelItem panel_id
                if FileSystem? and FileSystem.get_inst()?
                    fs = FileSystem.get_inst()
                    config_dir = FileSystem._home_dir + "/JaccarePanel" 
                    fs.load_or_make_dir config_dir, ( current_dir, err ) ->
                        file = current_dir.force_add_file panel._name.get(), panel, model_type: "JaccarePanelItem"
                        panel_id._name.set file.name.get()
                        panel_id._file = file
                        instance.add_child panel_id
                        instance._req_date.add 1
                        
                        
         context_action.push 
            txt: "Show table"
            ico: "img/add.png"
            fun: ( evt, app ) =>
                view_table = new TableView  @_tracker_completed, evt       

