function getUpdateXML() {
    let xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status ==  200) {
            var updateXML = xhr;
            displayXML(updateXML);//
        }
    }
    xhr.open("GET", "update.rss", true);
    xhr.send();
}

function displayXML(xml) {
    var xmlDoc = xml.responseXML;
    console.log(xmlDoc);
    xmlDoc = xml.responseXML;
    var output = "";
    x = xmlDoc.getElementsByTagName("item");
    for (var i = 0; i < x.length; i++) {
        var title = x[i].getElementsByTagName("title")[0].innerHTML;
        var link = x[i].getElementsByTagName("link")[0].innerHTML;
        var des = x[i].getElementsByTagName("description")[0].innerHTML;
        output += '<a href=' + link + '>' + title + '</a><br /><p>' + des + '</p><hr />';
    }
    document.body.innerHTML = document.body.innerHTML + output;
}

function getUpdateJSON() {
    let xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4 && xhr.status ==  200) {
            displayJSON(xhr);
        }
    }
    xhr.open("GET", "update.json");
    xhr.responseType = "json";
    xhr.send();
}

function displayJSON(json) {
    json = json.response;
    console.log(json);
    var output = "";
    for (var i = 0; i < json.items.length; i++) {
        var title = json.items[i].title;
        var link = json.items[i].link;
        var des = json.items[i].description;
        output += '<a href=' + link + '>' + title + '</a><br /><p>' + des + '</p><hr />';
    }
    document.body.innerHTML = document.body.innerHTML + output;
}

window.setInterval( function() {
    getUpdateJSON();
    getUpdateXML();
}, 1000);