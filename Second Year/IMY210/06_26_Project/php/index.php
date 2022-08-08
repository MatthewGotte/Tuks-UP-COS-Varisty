<?php

render_nav();
render_styles();
render_scripts();

if (isset($_GET['page'])) {
    $page = $_GET['page'];
    switch ($page) {
        case 'add_product':
            addProduct_form();
            break;
        case 'add_category':
            addCategory_form();
            break;
        case 'show_categories':
            listcategories();
            break;
    }
}

function listcategories() {
    header("Location: ../product/index.xml");
}

if (isset($_POST['category'])) {
    $category = $_POST['category'];
    if ($category == '') {
        echo '<h2 class="error">Error</h2>';
        echo '<h2 class="error">No string was submitted. Try again.';
        die();
    }
    if (!strpbrk($category, "\\/?%*:|\"<>") === FALSE) {
        echo '<h2 class="error">Error</h2>';
        echo '<h2 class="error">Invalid folder name provided. Remove special chars (\\/?%*:|\"<>).';
        die();
    }
    $xml = simplexml_load_file('../product/index.xml');
    foreach ($xml->category as $cat){
        if ($category == $cat) {
            echo '<h2 class="error">Error</h2>';
            echo '<h3 class="error">The submitted category already exists.';
            die();
        }
    }
    $dom = new DOMDocument();
    $dom->load('../product/index.xml');
    $newcategory = $dom->createElement('category');
    $node = $dom->createTextNode($category);
    $newcategory->appendChild($node);
    $dom->documentElement->appendChild($newcategory);
    //validate before write:
    if (!@$dom->schemaValidate('../xsd/validate.xsd')) {
        echo '<h2 class="error">Validation Error</h2>';
        echo '<h2 class="error">Name provided must not exceed 30 chars</h2>';
        die();
    }
    //create folders:
    mkdir('../product/' . $category);
    mkdir('../product/' . $category . '/Images');
    //scaffolding category (category > index.xml):
    $doc = new DOMDocument('1.0', 'utf-8');
    $doc->formatOutput = true;
    $xslt = $doc->createProcessingInstruction('xml-stylesheet', 'type="text/xsl" href="../../xsl/transformation.xsl"');
    $doc->appendChild($xslt);
    $root = $doc->createElement('index');
    $doc->appendChild($root);
    if (!@$doc->schemaValidate('../xsd/validate.xsd')) { //changed to doc from dom
        rmdir('../product/' . $category . '/images');
        rmdir('../product/' . $category);
        echo '<h2 class="error">Validation Error</h2>';
        echo '<h2 class="error">Scaffolding failed to build index.xml</h2>';
        die();
    }
    $doc->save('../product/' . $category . '/index.xml');
    $dom->save('../product/index.xml');
    echo '<h2 class="sent">Success</h2>';
    echo '<h3 class="sent">The Category "' . $category . '" has been added. Products can now be added to this category.';
}

if (isset($_POST['name'])) {
    //var_dump($_POST);
    //add prodct to catalog:
    $name = $_POST['name'];
    $id = md5($name);
    $stock = $_POST['stock'];
    $description = $_POST['description'];
    $category = $_POST['catagory'];
    $product_type = $_POST['product_type'];
    //get image here:
    $uploads_dir = '../product/' . $category . '/images';
    $target_file = basename($_FILES["upimage"]["name"]);
    move_uploaded_file($_FILES["upimage"]["tmp_name"], $uploads_dir . '/' . $id . '.' . strtolower(pathinfo($target_file,PATHINFO_EXTENSION)));
    $imagename = $id . '.' . strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
    $sale_price = $_POST['sale_price'];
    $currency = $_POST['currency'];
    $additional = false;
    if (isset($_POST['additional'])) {
        //with additional
        $additional = true;
        switch ($_POST['add']) {
            case 'xmlfile':
                //get from file
                $additional_content = file_get_contents($_FILES['upxmlfile']['tmp_name']);
                break;
            case 'xmltype':
                $additional_content = $_POST['upxmltype'];
                break;
        }
        //validate additional XML:
        @$sxe = simplexml_load_string($additional_content);
        if (!$sxe) {
            echo '<h2 class="error">Error</h2>';
            echo '<h3 class="error">The submitted additional XML was not well formed.</h3><br />';
        }
    }
    //var_dump($_FILES['upimage']);

    //update category's index.xml file:

    $catind = new DOMDocument();
    $catind->formatOutput = true;
    $catind->load('../product/' . $category . '/index.xml');
    $newproduct = $catind->createElement('product');
    $newproduct->setAttribute('id', $id);
    $node = $catind->createTextNode($name);
    $newproduct->appendChild($node);
    $catind->documentElement->appendChild($newproduct);

    //validate before write:
    if (!$catind->schemaValidate('../xsd/validate.xsd')) {
        echo '<h2 class="error">Validation Error</h2>';
        echo '<h2 class="error">Errors scaffolding the product directories.</h2>';
        die();
    }

    $catind->save('../product/' . $category . '/index.xml');

    //die();

    //make the product xml file here:
    $dom = new DOMDocument('1.0', 'utf-8');
    $dom->formatOutput = true;
    $xslt = $dom->createProcessingInstruction('xml-stylesheet', 'type="text/xsl" href="../../xsl/transformation.xsl"');
    $dom->appendChild($xslt);
    $root = $dom->createElement('product');
    $dom->appendChild($root);
    //add name
    $pname = $dom->createElement('name', $name);
    $root->appendChild($pname);
    //add id
    $pid = $dom->createElement('id', $id);
    $root->appendChild($pid);
    //add stock
    $pstock = $dom->createElement('stock', $stock);
    $root->appendChild($pstock);
    //add description
    $pdesc = $dom->createElement('description', $description);
    $root->appendChild($pdesc);
    //add category
    $pcategory = $dom->createElement('category', $category);
    $root->appendChild($pcategory);
    //add image
    $pimgage = $dom->createElement('image', $imagename);
    $root->appendChild($pimgage);
    //add available
    $pava = $dom->createElement('available', date("Y") . '-' . date("m") . '-' . date("d"));
    $root->appendChild($pava);
    //add sale price
    $psaleprice = $dom->createElement('sale_price', $sale_price);
    $psaleprice->setAttribute('currency', $currency);
    $root->appendChild($psaleprice);
    //add additional
    if ($additional == true) {
        $addon = $dom->createElement('additional', $additional_content);
        $root->appendChild($addon);
    } else $root->appendChild($dom->createElement('additional', ''));
    //append root to file
    //validate construction
    if (!$dom->schemaValidate('../xsd/validate.xsd')) {
        echo '<h2 class="error">Validation Error</h2>';
        echo '<h2 class="error">Validation on product xml failed.</h2>';
        die();
    }
    $dom->save('../product/' . $category . '/' . $id . '.xml');
    $temp = simplexml_load_file('../product/' . $category . '/' . $id . '.xml');
    echo '<h2 class="sent">Success - the following XML file has been generated.</h1>';
    echo '<h3>' . $id . '.xml</h3>';
    echo '<xmp>' . $temp->asXML() . '</xmp>';
}

function render_styles() {
    echo '<link rel="stylesheet" href="../css_js/style.css">';
}

function render_scripts() {
    echo '<script src="../css_js/script.js"></script>';
}

function render_nav() {
    echo
    '<h1 class="header">u20734621 - Project</h1>
    <div class="navbar">
        <a href="index.php?page=add_category">Add Category</a>
        <a href="index.php?page=add_product">Add Product</a>
        <a href="index.php?page=show_categories">View Categories</a>
    </div>
    ';
}

function addProduct_form() {

    echo
    '<div class="form_center">
    <form id="product_form" action="index.php" method="post"  charset="UTF-8" enctype="multipart/form-data">
    <p>Name:</p>
    <input id="productname" name="name" type="text"/>

    <br />

    <p>Stock:</p>
    <input id="productstock" name="stock" type="number"/>

    <br />

    <p>Description:</p>
    <input id="productdescription" name="description" type="text"/>

    <br />

    <p>Category:</p>
    <select id="cat" name="catagory">';

    //get all cats:
    $category = simplexml_load_file('../product/index.xml');
    foreach ($category->category as $cat){
        echo '<option value="' . $cat . '">' . $cat . '</option>';
    }

    echo
    '</select>

    <br />

    <p>Product Type:</p>
    <input id="producttype" name="product_type" type="text"/>

    <br />

    <div class="image_upload">
    <p>Image: </p>
    <input id="productimage" name="upimage" type="file"/>
    </div>

    <br />

    <p>Sale Price:</p>
    <div class="inline">
    <input id="productprice" name="sale_price" type="number"/>
    <p>in</p>
    <select id="currency" name="currency">
        <option value="USD">USD</option>
        <option value="ZAR">ZAR</option>
        <option value="EUR">EUR</option>
        <option value="GBP">GBP</option>
    </select>
    </div>

    <br />

    <div class="add">
    <input id="productadditional" onclick="add_click(this)" name="additional" type="checkbox" id="add"/>
    <p>Additionals tags to add?</p>
    </div>

    <div id="input_type">
        <input id="xmlfilechk" type="radio" name="add" onclick="add_method(this)" value="xmlfile"/>
        <label for="xmltype">Upload XML file</label><br />
        <input id="xmltypechk" type="radio" name="add" onclick="add_method(this)" value="xmltype"/>
        <label for="xmltype">Type XML here</label>
    </div>

    <textarea id="xmltype" rows=30 cols=35 name="upxmltype" placeholder="type XML here..."></textarea>

    <div id="xmlfile">
    <br/>
    <p>XML: </p>
    <input id="productxml" name="upxmlfile" type="file"/>
    </div>

    <br/>
    <input type = "button" onclick="productform(); return false;" value="Add Product"/>
    </form>
    </div>';

} 

function addCategory_form() {
    echo
    '<div class="form_center">
    <form id="category_form" action="index.php" method="post">
    <p>Name:</p>
    <input id="categoryinput" name="category" type="text"/>
    <br />
    <input type = "button" onclick="categoryform(); return false;" value="Add Category"/>
    </form>
    </div>';
}