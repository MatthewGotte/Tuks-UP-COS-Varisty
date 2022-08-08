var currmode = getCookie('theme');
if (currmode == null) {
    //make the cookie and set to dark:
    document.cookie = "theme=dark; expires=Fri, 31 Dec 9999 23:59:59 GMT";
}

if (currmode == 'light') {
    invert();
}

function swaptheme() {
    //alert();
    var color = document.getElementById("themeselect").value;
    if (currmode == color) {
        //alert('leave alone');
        return;
    }
    if (currmode == 'dark' && color == 'light') {
        //make light
        currmode = 'light';
        invert();
        document.cookie = "theme=light; expires=Fri, 31 Dec 9999 23:59:59 GMT";
        document.getElementById("themeselect").value = 'light';
        return;
    }
    if (currmode == 'light' && color == 'dark') {
        //make dark
        //currmode == 'dark';
        //invert();
        document.cookie = "theme=dark; expires=Fri, 31 Dec 9999 23:59:59 GMT";
        document.getElementById("themeselect").value = 'dark';
        currmode = 'dark';
        location.reload();
        return;
    }

}
//invert();

function tester() {
    //var prompt = "";
    var response = prompt("Please enter your prefered genre:\n-action\n-arcade\n-narrative\n-strategy\n-MMORPG", "");
    if (response != null) {
        //sent update to API:
        //console.log(JSON.stringify({ "type": "update", "setting" : "genre" , "value" : response, "key": API_key }));
        //return;
        $.ajax({
            type: "POST",
            url: "api.php",
            data: JSON.stringify({ "type": "update", "setting" : "genre" , "value" : response, "key": API_key }),
            contentType: "application/json",
            success: function (result) {
                if(result.status=="successful")
                {
                    alert("success, preference has been set.");
                }
                else
                {
                    //console.log(result);
    
                }
                return false;
            },
            error: function (result, status) {
                console.log('unsuccessful, let\'s try that again.');
            }
        });

    } else {
        alert("Please submit a valid response");
    }
}

/////////////////
function invert() {
    var output = 'html {filter: invert(100%);}img {filter: invert(100%);}#trending {filter: invert(100%);}#newReleases {filter: invert(100%);}#topRated {filter: invert(100%);}#featured {filter: invert(100%);}#calender {filter: invert(100%);}#dev {filter: invert(100%);}a {filter: invert(100%);}'
    var h = document.getElementsByTagName('head').item(0);
    var s = document.createElement("style");
    s.type = "text/css"; 
    s.appendChild(document.createTextNode(output));
    h.appendChild(s);
}

function showLoad() {
    $("#loading").show();
}

function hideLoad() {
    $("#loading").hide();
    console.log("hide");
}

function hideFooter() {
    $("body > div.footerback").hide()
}

function showFooter() {
    $("body > div.footerback").show();
}

var API_key = getCookie('API_key');
//console.log(API_key);
function getCookie(cname) {
    var name = cname + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    for(var i = 0; i <ca.length; i++) {
      var c = ca[i];
      while (c.charAt(0) == ' ') {
        c = c.substring(1);
      }
      if (c.indexOf(name) == 0) {
        return c.substring(name.length, c.length);
      }
    }
    return null;
}



//check cookie storage for data:
var data = getWithExpiry('data');
if (data != null) {
    data = data.data;
}
//console.log(data);
if (data == null) {
    console.log("XMLHTTPRequest in progress...");
    $.ajax({
        type: "POST",
        url: "api.php",
        data: JSON.stringify({ "type": "info", "return" : "*" , "title" : "*", "key": API_key }),
        async: false,
        contentType: "application/json",
        success: function (result) {
            if(result.status=="successful")
            {
                data = result.data;
                setWithExpiry('data', result, 25000);
            }
            else
            {
                //console.log(result);

            }
            return false;
        },
        error: function (result, status) {
            console.log('loading failed');
        }
    });

    //set storage with expire:
    
}

function setWithExpiry(key, value, ttl) {
	const now = new Date()

	// `item` is an object which contains the original value
	// as well as the time when it's supposed to expire
	const item = {
		value: value,
		expiry: now.getTime() + ttl,
	}
	localStorage.setItem(key, JSON.stringify(item));
}

function getWithExpiry(key) {
	const itemStr = localStorage.getItem(key);
    //console.log(itemStr);
	// if the item doesn't exist, return null
	if (!itemStr) {
		return null;
	}
	const item = JSON.parse(itemStr);
	const now = new Date();
	// compare the expiry time of the item with the current time
	if (now.getTime() > item.expiry) {
		// If the item is expired, delete the item from storage
		// and return null
		localStorage.removeItem(key);
		return null;
	}
	return item.value;
}


function onTrendingload() {
    console.log(data);
    $("#trendingMain").empty();
    for (var i = 0; i < 8; i++) {
        if (data[i] == null) continue;
        //GET DEVELOPER WITH REQUEST:
        var developers = "";
        if (data[i].developers.length != 0) {
            for (var t = 0; t < data[i].developers.length; t++) {
                developers += data[i].developers[t].name;
            }
        }
        else developers = "not found";
      
        ////////////////
        //Extracting the data from the dataect at [i]
        var heading = data[i].name;
        var releasedate = data[i].released;
        var rating = data[i].metacritic;
        var imgsrc = data[i].background_image;
        var genres = "";
        for (var p = 0; p < data[i].genres.length; p++) {
            genres += data[i].genres[p].name;
            if (p != data[i].genres.length - 1)
                genres += ", ";
        }
        var platforms = "";
        for (var p = 0; p < data[i].platforms.length; p++) {
            platforms += data[i].platforms[p].platform.name;
            if (p != data[i].platforms.length - 1)
                platforms += ", ";
        }
        var tags = "";
        var counter = 0;
        for (var p = 0; p < data[i].tags.length; p++) {
            if ((counter < 4) && (data[i].tags[p].language == "eng")) { //Takes the first 4 eng tags.
                tags += data[i].tags[p].name;
                if (counter != 3)
                    tags += ", ";
                    counter++;
            }
        }
        $("#trendingMain").append('<div class="gamecard" id="gamecard' + i + '"></div>');
        $("#gamecard" + i).append('<div class="gameimage" id="gameimage' + i + '"></div>');
        $("#gameimage" + i).append('<div class="titleblock" id="titleblock' + i + '">');
        $("#titleblock" + i).append('<h1 id="gamename">' + heading + '</h1>');
        $("#titleblock" + i).append('<h1 id="releasedate">' + releasedate + '</h1>');
        $("#titleblock" + i).append('<h1 id="rating">Rating&colon; ' + rating + '/100</h1>');

        $("#gameimage" + i).append('<div class="slidecontainer"><input type="range" min="1" max="100" value="50" class="slider" id="myRange"></div>');
        $("#gameimage" + i).append('<br />');
        $("#gameimage" + i).append('<br />');


//         
//   
// 
        $("#gameimage" + i).append('<img src="'+ imgsrc + '" alt="' + imgsrc + '">');
        $("#gameimage" + i).append('<div class="metadata" id="metadata' + i + '"></div>');
        $("#metadata" + i).append('<table class="data" id="data' + i + '"></table>');
        $("#data" + i).append("<tr>");
        $("#data" + i).append("<th>Developers&colon;</th>");
        $("#data" + i).append("<td>" + developers + "</td>");
        $("#data" + i).append("<th>Genre/s&colon;</th>");
        $("#data" + i).append("<td>" + genres + "</td>");
        $("#data" + i).append("</tr>");
        $("#data" + i).append("<tr>");
        $("#data" + i).append("<th>Platforms&colon;</th>");
        $("#data" + i).append("<td>" + platforms + "</td>");
        $("#data" + i).append("<th>Tags&colon;</th>");
        $("#data" + i).append("<td>" + tags + "</td>");
        $("#data" + i).append("</tr>");
        //console.log(heading, developers, releasedate, rating, imgsrc, genres, platforms, tags);
    }
    hideLoad();
    showFooter();   
}

function onnewReleasesload() {
    var small = 0;
    //hideLoad();
    var pos = 50;//starts at last card to avoid overlaps in card names, would be array length +1 if importing whole array
    for (var i = 1; i < 20; i++) {
            $("#newreleasesMainpage").append('<div class="smallcard" id="smallcard' + pos + '"></div>');
            for (var p = 0; p < 1; p++) {
                if (data[i+p] == null) {
                    control--;
                    p++;
                    continue;
                }
                var name = data[i + p].name;
                var releasedate = data[i + p].released;
                var uri = data[i + p].website;
                var imgsrc = data[i + p].background_image;
                var sysreq="";
                console.log(data[i+p])
                var developers = "";
                if (data[i+p].developers.length != 0) {
                    for (var t = 0; t < data[i].developers.length; t++) {
                        developers += data[i+p].developers[t].name;
                    }
                }
                else developers = "not found";
                var genres="";
                for (var q = 0; q < data[i + p].genres.length; q++) {
                    genres += data[i + p].genres[p].name;
                    if (q != data[i + p].genres.length - 1)
                        genres += ", ";
                }
                var platforms = 'not found';
                for (var q = 0; q < data[i+p].platforms.length; q++) {
                    platforms += data[i+p].platforms[q].platform.slug;
                    if (q != data[i+p].genres.length - 1)
                        platforms += ", ";
                }
                var sysreq = 'not found';
                for (var q = 0; q < data[i+p].platforms.length; q++) {
                    if (data[i+p].platforms[q].platform.slug == 'pc')
                    sysreq = data[i+p].platforms[q].requirements.minimum;
                }

                //console.log(name + " " + releasedate + " " + developers + " " + uri + " " + genres + " " + platforms)
                        
                    ////////////////
                //cards here
                $("#smallcard" + pos).append('<div class="gamecard" id="gamecard' + i+p + '"></div>');
                $("#gamecard" + i+p).append ('<div class="gameimage" id="gameimage' + i+p + '"></div>');
                
               

                $("#gameimage" + i+p).append('<div class="gameimage tooltip" id="tooltip' + i+p + '"></div>');
                $("#tooltip" + i+p).append('<span class="tooltiptext linear" id="linear' + i+p + '"></span>');
                $("#linear" + i+p).append('<h1 id="tipheader">' + name + '</h1>');
                $("#tooltip" + i+p).append('<img src="' + imgsrc + '"></img>');
                $("#gameimage" + i + p).append('<div class="slidecontainer"><input type="range" min="1" max="100" value="50" class="slider" id="myRange"></div>');
                $("#gameimage" + i + p).append('<br />');
                $("#gameimage" + i + p).append('<br />');
                $("#gameimage" + i+p).append('<div class="titleblock" id="titleblock' + i+p + '"></div>');
                $("#titleblock" + i+p).append('<h1 id="releasedate">' + releasedate + '</h1>');
                $("#gameimage" + i+p).append('<div class="metadata" id="metadata' + i+p + '"></div>');
                $("#metadata" + i+p).append('<table class="data" id="data' + i+p + '"></table>');
                $("#data" + i+p).append("<tr>");
                $("#data" + i+p).append("<th>Developers&colon;</th>");
                $("#data" + i+p).append('<td>' + developers + '</td>');
                $("#data" + i+p).append("</tr>");
                $("#data" + i+p).append("<tr>");
                $("#data" + i+p).append("<th>URI&colon;</th>");
                $("#data" + i+p).append('<td><a class="gamelink" href="' + uri + '">Click Here</a></td>');
                $("#data" + i+p).append("</tr>");
                $("#data" + i+p).append("<tr>");
                $("#data" + i+p).append("<th>Genre/s&colon;</th>");
                $("#data" + i+p).append('<td>' + genres + '</td>');
                $("#data" + i+p).append("<tr>");
                $("#data" + i+p).append("</tr>");
                $("#data" + i+p).append("<th>Platforms&colon;</th>");
                $("#data" + i+p).append('<td>' + platforms + '</td>');
                $("#data" + i+p).append("</tr>");
                $("#data" + i+p).append("<tr>");
                $("#data" + i+p).append("<th>System Requirements&colon;</th>");
                $("#data" + i+p).append('<td>' + sysreq + '</td>');
                $("#data" + i+p).append("</tr>");
            }
            i += 2;
            small = 0;
            pos++;
        //console.log(name, releasedate, developer, uri, genre, agerating, platforms, imgsrc);
    }
    hideLoad();
    showFooter();
}

function onTopRatedload() {
    for (var i = 40; i < 65; i++) {
        if (data[i] == null) continue;
        //EXPLIN WHY THIS IS A FALSE SYNC CALL!
        //GET DEVELOPER WITH REQUEST:
        var developers = "";
        if (data[i].developers.length != 0) {
            for (var t = 0; t < data[i].developers.length; t++) {
                developers += data[i].developers[t].name;
            }
        }
        else developers = "not found";
        ////////////////
        //Extracting the data from the object at [i]
        var heading = data[i].name;
        var releasedate = data[i].released;
        var rating = data[i].metacritic;
        if (data[i].matacritic == null) rating = 'not found';
        var imgsrc = data[i].background_image;
        var genres = "";
        for (var p = 0; p < data[i].genres.length; p++) {
            genres += data[i].genres[p].name;
            if (p != data[i].genres.length - 1)
                genres += ", ";
        }
        var platforms = "";
        for (var p = 0; p < data[i].platforms.length; p++) {
            platforms += data[i].platforms[p].platform.name;
            if (p != data[i].platforms.length - 1)
                platforms += ", ";
        }
        var stores = "";
        for (var p = 0; p < data[i].stores.length; p++) {
            stores += data[i].stores[p].store.name;
            if (p != data[i].stores.length - 1)
                stores += ", ";
        }
        var tags = "";
        var counter = 0;
        for (var p = 0; p < data[i].tags.length; p++) {
            if ((counter < 4) && (data[i].tags[p].language == "eng")) { //Takes the first 4 eng tags.
                tags += data[i].tags[p].name;
                if (counter != 3)
                    tags += ", ";
                    counter++;
            }
        }
        var series= "not found";
        $("#topRatedMain").append('<div class="gamecard" id="gamecard' + i + '"></div>');
        $("#gamecard" + i).append('<div class="gameimage" id="gameimage' + i + '"></div>');
        
        $("#gameimage" + i).append('<div class="titleblock" id="titleblock' + i + '">');
        $("#titleblock" + i).append('<h1 id="gamename">' + heading + '</h1>');
        $("#titleblock" + i).append('<h1 id="releasedate">' + releasedate + '</h1>');
        $("#gameimage" + i).append('<div class="slidecontainer"><input type="range" min="1" max="100" value="50" class="slider" id="myRange"></div>');
        $("#gameimage" + i).append('<br />');
        $("#gameimage" + i).append('<br />');
        $("#gameimage" + i).append('<img src="'+ imgsrc + '" alt="' + 'Image not found' + '">');
        $("#gameimage" + i).append('<div class="metadata" id="metadata' + i + '"></div>');
        $("#metadata" + i).append('<table class="data" id="data' + i + '"></table>');
        $("#data" + i).append("<tr>");
        $("#data" + i).append("<th>Developers&colon;</th>");
        $("#data" + i).append("<td>" + developers + "</td>");
        $("#data" + i).append("<th>Genre/s&colon;</th>");
        $("#data" + i).append("<td>" + genres + "</td>");
        $("#data" + i).append("</tr>");
        $("#data" + i).append("<tr>");
        $("#data" + i).append("<th>Platforms&colon;</th>");
        $("#data" + i).append("<td>" + platforms + "</td>");
        $("#data" + i).append("<th>Metacritic Rating&colon;</th>");
        $("#data" + i).append("<td>" + rating + "</td>");
        $("#data" + i).append("</tr>");
        $("#data" + i).append("<tr>");
        $("#data" + i).append("<th>Stores&colon;</th>");
        $("#data" + i).append("<td>" + stores + "</td>");
        $("#data" + i).append("<th>Series&colon;</th>");
        $("#data" + i).append("<td>" + series + "</td>");
        $("#data" + i).append("</tr>");
        //console.log(heading, developers, releasedate, rating, imgsrc, genres, platforms, tags);
    }
    hideLoad();
    showFooter();
}

function onFeaturedload() {
    var small = 0;
    
    var pos = 100;//starts at last card to avoid overlaps in card names, would be array length +1 if importing whole array
    for (var i = 10; i < 60; i++) {
        $("#featuredMainpage").append('<div class="smallcard" id="smallcard' + pos + '"></div>');
        for (var p = 0; p < 2; p++) {
            console.log("ran");
            if (data[i+p] == null) {
                continue;
            }
            console.log(data[i+p]);
            var name = data[i + p].name;
            var releasedate = data[i + p].released;
            var developers = "";
            if (data[i].developers.length != 0) {
                for (var t = 0; t < data[i].developers.length; t++) {
                    developers += data[i].developers[t].name;
                }
            }
            else developers = "not found";
            console.log(data[i+p].genres);
            var genres = "";
            for (var q = 0; q < data[i+p].genres.length; q++) {
                genres += data[i+p].genres[q].name;
                if (q != data[i].genres.length - 1)
                    genres += ", ";
            }
            //var platforms = data[i + p].platform;
            var platforms = "";
            for (var ep = 0; ep < data[i].platforms.length; ep++) {
                platforms += data[i].platforms[ep].platform.name;
                if (ep != data[i].platforms.length - 1)
                    platforms += ", ";
            }
            var imgsrc = data[i + p].background_image;
            var desc = data[i + p].description_raw;
            //var tempname = name.replace(/\s/g, '-');
            //1console.log(temp);
            var rating ="not found";


                if (data[i+p].metacritic != null) {
                    rating = data[i+p].metacritic;
                }   

            //cards here
            $("#smallcard" + pos).append('<div class="gamecard" id="gamecard' + i+p + '"></div>');
            $("#gamecard" + i+p).append ('<div class="gameimage" id="gameimage' + i+p + '"></div>');
            $("#gameimage" + i+p).append('<div class="gameimage tooltip" id="tooltip' + i+p + '"></div>');
            $("#gameimage" + i+p).append('<h1 id="tipheader" style="text-align: center">' + name + '</h1>');
            $("#gameimage" + i+p).append('<img src="' + imgsrc + '"></img>');
            $("#gameimage" + i+p).append('<div class="titleblock" id="titleblock' + i+p + '"></div>');
            $("#titleblock" + i+p).append('<h1 id="releasedate">' + releasedate + '</h1>');

            $("#gameimage" + i + p).append('<div class="slidecontainer"><input type="range" min="1" max="100" value="50" class="slider" id="myRange"></div>');
            $("#gameimage" + i + p).append('<br />');
            $("#gameimage" + i + p).append('<br />');

            $("#gameimage" + i+p).append('<div class="metadata" id="metadata' + i+p + '"></div>');
            $("#metadata" + i+p).append('<table class="data" id="data' + i+p + '"></table>');
            $("#data" + i+p).append("<tr>");
            $("#data" + i+p).append('<td colspan=2 style="text-align: justify">' + desc + '</td>');
            $("#data" + i+p).append("</tr>");
            $("#data" + i+p).append("<tr>");
            $("#data" + i+p).append("<th>Developers&colon;</th>");
            $("#data" + i+p).append('<td>' + developers + '</td>');
            $("#data" + i+p).append("</tr>");
            $("#data" + i+p).append("<tr>");
            $("#data" + i+p).append("<th>Genre/s&colon;</th>");
            $("#data" + i+p).append('<td>' + genres + '</td>');
            $("#data" + i+p).append("<tr>");
            $("#data" + i+p).append("</tr>");
            $("#data" + i+p).append("<th>Platforms&colon;</th>");
            $("#data" + i+p).append('<td>' + platforms + '</td>');
            $("#data" + i+p).append("</tr>");
            $("#data" + i+p).append("<tr>");
            $("#data" + i+p).append("<th>Metacritic Rating&colon;</th>");
            $("#data" + i+p).append('<td>' + rating + '</td>');
            $("#data" + i+p).append("</tr>");
        }
        i += 2;
        small = 0;
        pos++;
        //console.log(name, releasedate, developer, uri, genre, agerating, platforms, imgsrc);
    }
    hideLoad();
    showFooter();
}

//SEARCHING////////////////////
$(document).ready(function() {
    try {
        var input = document.getElementById("textsearch");
        input.addEventListener("keyup", function(event) {
        if (event.keyCode === 13) {
            event.preventDefault();
            document.getElementById("search").click();
        }
        });
    }
    catch(e) {
        
    }
});


function searchTrending() {    
    $( ".gamecard" ).each(function(i) {
        var cname = data[i].name;
        cname = cname.toLowerCase();
        console.log(cname);
        var term = document.getElementById("textsearch").value;
        if (term != null) {
            term = term.toLowerCase();
            var filter = document.getElementById("filterTrending").value;
            console.log(filter);
            if (cname.includes(term)) {
                if (filter != null) {
                    var genres="";
                    for (var p = 0; p < data[i].genres.length; p++) {
                        genres += data[i].genres[p].name;
                        if (p != data[i].genres.length - 1)
                            genres += ", ";
                    }
                    genres = genres.toLowerCase();
                    filter = filter.toLowerCase();
                    if (!genres.includes(filter)) {
                        $(this).hide();
                    }
                    else {
                        $(this).show();
                    }
                } 
            }
            else $(this).hide();
        }
        console.log("->" +this);
        alert();
    });
    notfound();
    checkVis();
}

function searchTopRated() {
    $( ".gamecard" ).each(function(i) {
        var cname = data.results[i].name;
        cname = cname.toLowerCase();
        console.log(cname);
        var term = document.getElementById("textsearch").value;
        if (term != null) {
            term = term.toLowerCase();
            var filter = document.getElementById("filterTopRated").value;
            console.log(filter);
            if (cname.includes(term)) {
                if (filter != null) {
                    var genres="";
                    for (var p = 0; p < data[i].genres.length; p++) {
                        genres += data[i].genres[p].name;
                        if (p != data[i].genres.length - 1)
                            genres += ", ";
                    }
                    genres = genres.toLowerCase();
                    filter = filter.toLowerCase();
                    if (!genres.includes(filter)) {
                        $(this).hide();
                    }
                    else {
                        $(this).show();
                    }
                } 
            }
            else $(this).hide();
        }
    });
    notfound();
    checkVis();
}

/////////////
function searchNewReleases() {
    $(".smallcard").each(function(out) {
        $( ".gamecard" ).each(function(i) {
            var cname = data[i].title;
            cname = cname.toLowerCase();
            console.log(cname);
            var term = document.getElementById("textsearch").value;
            if (term != null) {
                term = term.toLowerCase();
                var filter = document.getElementById("filterNewReleases").value;
                console.log(filter);
                if (cname.includes(term)) {
                    if (filter != null) {
                        var genres = data[i].genre;
                        genres = genres.toLowerCase();
                        filter = filter.toLowerCase();
                        if (!genres.includes(filter)) {
                            $(this).hide();
                        }
                        else {
                            $(this).show();
                        }
                    } 
                }
                else $(this).hide();
            }
        });
    });
    notfound();
    checkVis();
}
/////////////
function searchFeatured() {
        $(".smallcard").each(function(out) {
        $( ".gamecard" ).each(function(i) {
            i = i + parseInt(data.length / 2);
            var cname = data[i].title;
            cname = cname.toLowerCase();
            console.log(cname);
            var term = document.getElementById("textsearch").value;
            if (term != null) {
                term = term.toLowerCase();
                var filter = document.getElementById("filterFeatured").value;
                console.log(filter);
                if (cname.includes(term)) {
                    if (filter != null) {
                        var genres = data[i].genre;
                        genres = genres.toLowerCase();
                        filter = filter.toLowerCase();
                        if (!genres.includes(filter)) {
                            $(this).hide();
                        }
                        else {
                            $(this).show();
                        }
                    } 
                }
                else $(this).hide();
            }
        });
    });
    notfound();
    checkVis();
}

function notfound() {
    $("#notfound").show();
}

function found() {
    $("#notfound").hide();
}

function checkVis() {
    $(".gamecard").each(function (i) {
        if ($( this ).is(":visible")) {
            found();
            return;
        }
    });
}


function refreshPage(){
    window.location.reload();
} 

var monthNames = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

var showingMonth;
var showingYear;

function generateCurrentCalender() {
    $("#calenderMainpage").empty();
    $("#calenderMainpage").hide();
    var current = new Date();
    showingMonth = current.getMonth();
    showingYear = current.getFullYear();
    document.getElementById("year").innerHTML = showingYear;
    document.getElementById("month").innerHTML = monthNames[showingMonth] + "&nbsp;";
    createCalendar(showingYear, showingMonth + 1);
    
}

function nextMonth() {
    $("#calenderMainpage").empty();
    if (showingMonth == 11) {
        showingYear++;
        showingMonth = 0;
    }
    else {
        showingMonth++;
    }
    createCalendar(showingYear, showingMonth);
    document.getElementById("year").innerHTML = showingYear;
    document.getElementById("month").innerHTML = monthNames[showingMonth] + "&nbsp;";
}

function prevMonth() {
    $("#calenderMainpage").empty();
    if (showingMonth == 1) {
        showingYear--;
        showingMonth = 12;
    }
    else {
        showingMonth--;
    }
    createCalendar(showingYear, showingMonth);
    document.getElementById("year").innerHTML = showingYear;
    document.getElementById("month").innerHTML = monthNames[showingMonth - 1] + "&nbsp;";
}

var api1 = null;
var api2 = null;
var temp = [];

function createCalendar(year, month) {

    //API CALLS
    if (api2 == null) {
        const data = null;
        const req2 = new XMLHttpRequest();
        req2.withCredentials = true;
        req2.addEventListener("readystatechange", function () {
            if (this.readyState === this.DONE) {
                api2 = JSON.parse(this.responseText);
            }
        });
        req2.open("GET", "https://free-to-play-games-database.p.rapidapi.com/api/filter?tag=action", false);
        req2.setRequestHeader("x-rapidapi-key", "e25b776e64mshee562e432cc9115p1dcda5jsn47748f35359b");
        req2.setRequestHeader("x-rapidapi-host", "free-to-play-games-database.p.rapidapi.com");
        req2.send(); 
    }
    if (api1 == null) {
        var req = new XMLHttpRequest();
        req.onreadystatechange = function() {
            if(this.readyState == 4 && this.status == 200) {
                api1 = JSON.parse(this.responseText);
                api1 = api1.results;
                $("#calenderMainpage").show();
            }
        };
        req.open("GET", "https://api.rawg.io/api/games?key=114d98eeb30f4a67ae8e42a8eca9240d&dates=2019-09-01,2019-09-30&platforms=18,1,7", false);
        req.send(); 
    }
    
    for (var i = 100; i < 125; i++) {
        temp.push({"released": api2[i].release_date, "name": api2[i].title});
    }
    for (var i = parseInt(temp.length / 2); i < parseInt(temp.length / 2) + 15; i++) {
        try {
            temp.push({"released": api2[i].release_date, "name": api2[i].title});
        }
        catch(e) {
            
        }
    }
    for (var i = 0; i < api1.length; i++) {
        temp.push({"released": api1[i].released, "name": api1[i].name});
    }

    console.log(temp);

    $("#loading").remove();
    let mon = month - 1; // months in JS are 0..11, not 1..12
    let d = new Date(year, mon);

    let table = '<table id="gamecalender"><tr><th>MON</th><th>TUE</th><th>WED</th><th>THUR</th><th>FRI</th><th>SAT</th><th>SUN</th></tr><tr>';

    for (let i = 0; i < getDay(d); i++) {
      table += '<td></td>';
    }
    while (d.getMonth() == mon) {

        var output = "<br>";

        try {
            for (var q = 0; q < temp.length; q++) {
                var tyear  = temp[q].released;
                tyear = parseInt(tyear.substr(0,4));
                if (tyear == d.getFullYear()) {
                    var tmonth = temp[q].released;
                    tmonth = parseInt(tmonth.substr(5,2));
                    if (month == tmonth) {
                        tday = temp[q].released;
                        tday = parseInt(tday.substr(8,2));
                        if (d.getDate() == tday) {
                            output += temp[q].name + "<br><br>";
                            temp.slice(q, 1);
                            break;
                        }
                    } 
                }

                
            }
        }
        catch(e) {

        }

      table += '<td><p>' + d.getDate() + '</p><p style="color:white"'+ output + '</p></td>';

      if (getDay(d) % 7 == 6) {
        table += '</tr><tr>';
      }

      d.setDate(d.getDate() + 1);
    }
    if (getDay(d) != 0) {
      for (let i = getDay(d); i < 7; i++) {
        table += '<td></td>';
      }
    }
    table += '</tr></table>';
    $("#calenderMainpage").append(table);
  }
  function getDay(date) { 
    let day = date.getDay();
    if (day == 0) day = 7; 
    return day - 1;
}

function showtoday() {
    $("#notfound").show();
    document.getElementById("today").disabled = true;
    document.getElementById("prev").disabled = true;
    document.getElementById("next").disabled = true;
    $( "#calenderMainpage" ).empty();
    $( "#calenderMainpage" ).append('<div id="todaycard"></div>');
    var currdate = "";
    var d = new Date();
    var month, date;
    if (d.getMonth() + 1 < 10)
        month = "0" + (d.getMonth() + 1);
    else month = d.getMonth();
    if (d.getDate() < 10) 
        day = "0" + d.getDate();
    else day = d.getDate();
    currdate += d.getFullYear() + "-" + month + "-" + day;
    document.getElementById("month").innerHTML = d.getDate() + " " + monthNames[d.getMonth()] + "&nbsp;";
    document.getElementById("year").innerHTML = d.getFullYear();
    //console.log(temp);
    for (var i = 0; i < temp.length; i++) {
        if (temp[i].released == currdate) {
            $("#calenderMainpage").append('<h1 id="gamename">' + temp[i].name + '</h1>');
            $("#notfound").hide();
        }
    }
}