# Copyright 2012 Structure Computation  www.structure-computation.com
# Copyright 2014 jeremie Bellec
#
# This file is part of Soda.
#
# Soda is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Soda is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with Soda. If not, see <http://www.gnu.org/licenses/>.



#

class TableView extends View
    constructor: ( model, evt ) ->
        super model
        @model = model
        
        @container_global = new_dom_element
            id : "Table_container"
            nodeName   : "div"
            style:
                overflowY: "hidden"
                overflowX: "hidden"
                #backgroundColor : "#ffffff"
        
        Ptop   = 100
        Pleft  = 100
        Pwidth = 800 
        Pheight = 300 
        
        #@myWindow = window.open '_','_blank','width=400,height=500,resizable=1'
        #@myWindow.document.body.appendChild @container_global
        
        p = new_popup "Message", event: evt, child: @container_global, top_x: Pleft, top_y: Ptop, width: Pwidth, height: Pheight, background: "#262626",  onclose: =>
            @onPopupClose( )
        
    onchange:()->
        @clear_page(@container_global)
        table = new_dom_element
            parentNode : @container_global
            nodeName   : "div"
            style:
                cssFloat   : "left"
                width      : "98%"
                margin     : "0px 0 0 0px"
                height     : "250"
                border     : "1px solid grey"
                #backgroundColor : "#ffffff"
                overflowY: "auto"
        
        @view_model_table(table)
        
                
        
    onPopupClose: ( ) =>
        document.onkeydown = undefined
        @clear_page(@container_global)
    
    clear_page: ( div_to_clear ) ->
        while div_to_clear.firstChild?
            div_to_clear.removeChild div_to_clear.firstChild
    
    view_model_table: ( parent ) ->
        for lign in @model
            lign_cont = new_dom_element
                parentNode : parent
                nodeName   : "div"
                style:
                    cssFloat   : "left"
                    width      : "100%"
                    height     : "20px"
                    margin     : "1px 0 0 0px"
#                     background : "blue"
                      
            nb_column = 0
            for column in lign._attribute_names
                nb_column += 1
#             console.log nb_column
            
            _width = @get_width lign_cont
            col_width = (750 / nb_column) - 3
#             console.log _width
            
            
#             console.log lign._attribute_names
            
            for column in lign._attribute_names
                column_cont = new_dom_element
                    parentNode : lign_cont
                    nodeName   : "div"
                    txt        : lign[column].get()
                    style:
                        cssFloat   : "left"
                        width      : col_width
                        margin     : "0px 3px 0px 0px"
                        height     : "20px"
                        textAlign  : "center"
                        color      : "black"
                        background : "#ffffff"
            
    
    
    get_width: ( div ) ->
        txt_id = ""
        divid = div.id
        if divid?
            txt_id = "#" + divid
        
        else
            div.id = @get_unit_view_id()
            txt_id = "#" + div.id
#         console.log txt_id
        width = $(txt_id).width()
        return width
 