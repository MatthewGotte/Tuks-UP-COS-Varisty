function add_click(val) {
    var file = document.getElementById("xmlfile");
    var type = document.getElementById("xmltype");
    file.style.display = "none";
    type.style.display = "none";
    var temp = document.getElementById("input_type");
    temp.style.display = val.checked ? "block" : "none";
}

function add_method(val) {
    var file = document.getElementById("xmlfile");
    var type = document.getElementById("xmltype");
    if (val.value == "xmlfile") {
        file.style.display = "block";
        type.style.display = "none";
    }
    else {
        type.style.display = "block";
        file.style.display = "none";
    }
    
    //alert();
}

function categoryform() {
    var input = document.getElementById("categoryinput").value;
    if (input == '')
        alert ("Please submit a valid value.");
    else {
        document.getElementById("category_form").submit();
    }
}

function productform() {
    if (!validateproductform()) {
        alert("Form is not valid. Please fill in all fields.");
        return;
    }
    document.getElementById("product_form").submit();
}

function validateproductform() {
    var name = document.getElementById("productname").value;
    if (name == '') return false;
    var stock = document.getElementById("productstock").value;
    if (stock == '') return false;
    var desc =  document.getElementById("productdescription").value;
    if (desc == '') return false;
    var type = document.getElementById("producttype").value;
    if (type == '') return false;
    var imagefile = document.getElementById("productimage").files.length;
    if (imagefile == 0) return false;
    var price = document.getElementById("productprice").value;
    if (price == 0) return false;

    var add = document.getElementById("productadditional");
    if (add.checked != false) {
        //validate the additionals here:
        //get 
        var fileinput = document.getElementById("xmlfilechk").checked;
        var xmlinput = document.getElementById("xmltypechk").checked;

        if (fileinput == false && xmlinput == false) return false;

        if (fileinput == true) {
            //validate file was attatched:
            var imagefile = document.getElementById("productxml").files.length;
            if (imagefile == 0) return false;
        }
        else {
            //validate that text submitted:
            var area = document.getElementById("xmltype").value;
            if (area == '') return false;
        }
    }

    return true;
}