#
class JaccarePanelFileItem extends TreeItem_Automatic
    constructor: ( name = "panel_initiate" ) ->
        super()
        
        @_name.set name
        @_viewable.set false
        
        @add_attr
            ID          : -1            #ID du panel, pour le manager
            DateTime    : ""            #date de mise en service
            pos         : []            #position géographique du panneau
            ID_file     : -1            #ID du file qui contient les informations du panel
            registered  : false
            active      : false
            _file       : new Model
                    
              
        @bind =>
            if  @ID.has_been_modified() and @ID.get() != -1 and @registered.get() == false
                #création et ajout du fichier panel
                @_file.name.set @_name.get()
                @registered.set true
                console.log @_file
            

    display_suppl_context_actions: ( context_action )  ->
        context_action.push 
            txt: "test new panel"
            ico: "img/add.png"
            fun: ( evt, app ) =>
                console.log @ID.get()
                console.log @ID_file.get()
                console.log @has_file.get()
                console.log @_name.get()
                @_file._ptr.load ( m, err ) =>
                    model = m
                    console.log model
