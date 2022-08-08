function showLoad() {
    $("#loading").show();
}

function hideLoad() {
    $("#loading").hide();
}

function hideFooter() {
    $("body > div.footerback").hide()
}

function showFooter() {
    $("body > div.footerback").show();
}


var trendobj;
//TRENDING
function onTrendingload() {
    hideFooter();
    var req = new XMLHttpRequest();
    req.onreadystatechange = function() {
        if(this.readyState == 4 && this.status == 200) {
            trendobj = JSON.parse(this.responseText);
            //console.log(object.results[0].background_image);
            showFooter();
            hideLoad();
            populateTrending(trendobj.results, true);
        }
    };
    req.open("GET", "https://api.rawg.io/api/games?key=114d98eeb30f4a67ae8e42a8eca9240d&dates=2019-09-01,2019-09-30&platforms=18,1,7", true);
    req.send();
}

function populateTrending(obj) {
    console.group("Trending Load");
    console.log(obj);
    
    //hide was here
    $("#trendingMain").empty();
    for (var i = 0; i < 10; i++) {
        //EXPLIN WHY THIS IS A FALSE SYNC CALL!
        //GET DEVELOPER WITH REQUEST:
        var temp;
        var req = new XMLHttpRequest();
        req.onreadystatechange = function() {
            if(this.readyState == 4 && this.status == 200) {
                temp = JSON.parse(this.responseText);
                
            }
        };
        req.open("GET", 'https://api.rawg.io/api/games/' + obj[i].id + '?key=114d98eeb30f4a67ae8e42a8eca9240d&dates=2019-09-01,2019-09-30&platforms=18,1,7', false);
        req.send();
        console.log(temp);
        var developers = "";
        if (temp.developers.length != 0) {
            for (var t = 0; t < temp.developers.length; t++) {
                developers += temp.developers[t].name;
            }
        }
        else developers = "not found";
        ////////////////
        //Extracting the data from the object at [i]
        var heading = obj[i].name;
        var releasedate = obj[i].released;
        var rating = obj[i].metacritic;
        var imgsrc = obj[i].background_image;
        var genres = "";
        for (var p = 0; p < obj[i].genres.length; p++) {
            genres += obj[i].genres[p].name;
            if (p != obj[i].genres.length - 1)
                genres += ", ";
        }
        var platforms = "";
        for (var p = 0; p < obj[i].platforms.length; p++) {
            platforms += obj[i].platforms[p].platform.name;
            if (p != obj[i].platforms.length - 1)
                platforms += ", ";
        }
        var tags = "";
        var counter = 0;
        for (var p = 0; p < obj[i].tags.length; p++) {
            if ((counter < 4) && (obj[i].tags[p].language == "eng")) { //Takes the first 4 eng tags.
                tags += obj[i].tags[p].name;
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
}

//New Releases
var newreleaseobj;
function onnewReleasesload() {
    hideFooter();
    const data = null;
    const req = new XMLHttpRequest();
    req.withCredentials = true;
    req.addEventListener("readystatechange", function () {
        if (this.readyState === this.DONE) {
            newreleaseobj = JSON.parse(this.responseText);
            populatenewreleasesload(newreleaseobj);
            hideLoad();
            showFooter();
        }
    });
    req.open("GET", "https://free-to-play-games-database.p.rapidapi.com/api/filter?tag=action");
    req.setRequestHeader("x-rapidapi-key", "e25b776e64mshee562e432cc9115p1dcda5jsn47748f35359b");
    req.setRequestHeader("x-rapidapi-host", "free-to-play-games-database.p.rapidapi.com");
    req.send();
}

function populatenewreleasesload(obj) {
    console.group('New Release Load')
    console.log(obj);
    var small = 0;
    //hideLoad();
    var pos = 126;//starts at last card to avoid overlaps in card names, would be array length +1 if importing whole array
    for (var i = 100; i < 125; i++) {
            $("#newreleasesMainpage").append('<div class="smallcard" id="smallcard' + pos + '"></div>');
            for (var p = 0; p < 2; p++) {

                var name = obj[i + p].title;
                var releasedate = obj[i + p].release_date;
                var developer = obj[i + p].developer;
                var uri = obj[i + p].game_url;
                var genre = obj[i + p].genre;
                var platforms = obj[i + p].platform;
                var imgsrc = obj[i + p].thumbnail;
                var sysreq="";
                var tempname = name.replace(/\s/g, '-');
                        //GET SYSREQ. WITH REQUEST:
                        try {
                            var temp;
                            var req = new XMLHttpRequest();
                            req.onreadystatechange = function() {
                                if(this.readyState == 4 && this.status == 200) {
                                    temp = JSON.parse(this.responseText);
                                }
                            };
                            req.open("GET", 'https://api.rawg.io/api/games/' + tempname + '?&key=114d98eeb30f4a67ae8e42a8eca9240d&dates=2019-09-01,2019-09-30&platforms=18,1,7', false);
                            req.send();
                        }
                        catch (e) {
                        }
                        if (temp != null) {
                            for (var a = 0; a < temp.platforms.length; a++) {
                                if (temp.platforms[a].platform.slug = "pc") {
                                    if (temp.platforms[a].requirements.minimum != null)
                                    sysreq = temp.platforms[a].requirements.minimum;
                                    else sysreq = "not found";
                                }
                            }
                        }
                        else {
                            sysreq = "not found";
                        }
                    ////////////////
                //cards here
                $("#smallcard" + pos).append('<div class="gamecard" id="gamecard' + i+p + '"></div>');
                $("#gamecard" + i+p).append ('<div class="gameimage" id="gameimage' + i+p + '"></div>');
                $("#gameimage" + i+p).append('<div class="gameimage tooltip" id="tooltip' + i+p + '"></div>');
                $("#tooltip" + i+p).append('<span class="tooltiptext linear" id="linear' + i+p + '"></span>');
                $("#linear" + i+p).append('<h1 id="tipheader">' + name + '</h1>');
                $("#tooltip" + i+p).append('<img src="' + imgsrc + '"></img>');
                $("#gameimage" + i+p).append('<div class="titleblock" id="titleblock' + i+p + '"></div>');
                $("#titleblock" + i+p).append('<h1 id="releasedate">' + releasedate + '</h1>');
                $("#gameimage" + i+p).append('<div class="metadata" id="metadata' + i+p + '"></div>');
                $("#metadata" + i+p).append('<table class="data" id="data' + i+p + '"></table>');
                $("#data" + i+p).append("<tr>");
                $("#data" + i+p).append("<th>Developers&colon;</th>");
                $("#data" + i+p).append('<td>' + developer + '</td>');
                $("#data" + i+p).append("</tr>");
                $("#data" + i+p).append("<tr>");
                $("#data" + i+p).append("<th>URI&colon;</th>");
                $("#data" + i+p).append('<td><a class="gamelink" href="' + uri + '">Click Here</a></td>');
                $("#data" + i+p).append("</tr>");
                $("#data" + i+p).append("<tr>");
                $("#data" + i+p).append("<th>Genre/s&colon;</th>");
                $("#data" + i+p).append('<td>' + genre + '</td>');
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
}

let topratedobj;
//ontopRatedload
function onTopRatedload() {
    hideFooter();
    var req = new XMLHttpRequest();
    req.onreadystatechange = function() {
        if(this.readyState == 4 && this.status == 200) {
            topratedobj = JSON.parse(this.responseText);
            //console.log(object.results[0].background_image);
            populateTopRated(topratedobj.results);
            hideLoad();
            showFooter();
        }
    };
    req.open("GET", "https://api.rawg.io/api/games?key=114d98eeb30f4a67ae8e42a8eca9240d&dates=2019-09-01,2019-09-30&platforms=18,1,7", true);
    req.send();
}

function populateTopRated(obj) {
    console.group("Top Rated Load");
    console.log(obj);
    
    for (var i = obj.length / 2; i < obj.length; i++) {
        //EXPLIN WHY THIS IS A FALSE SYNC CALL!
        //GET DEVELOPER WITH REQUEST:
        var temp;
        var req = new XMLHttpRequest();
        req.onreadystatechange = function() {
            if(this.readyState == 4 && this.status == 200) {
                temp = JSON.parse(this.responseText);
            }
        };
        req.open("GET", 'https://api.rawg.io/api/games/' + obj[i].id + '?key=114d98eeb30f4a67ae8e42a8eca9240d&dates=2019-09-01,2019-09-30&platforms=18,1,7', false);
        req.send();
        console.log(temp);
        var developers = "";
        if (temp.developers.length != 0) {
            for (var t = 0; t < temp.developers.length; t++) {
                developers += temp.developers[t].name;
            }
        }
        else developers = "not found";
        ////////////////
        //Extracting the data from the object at [i]
        var heading = obj[i].name;
        var releasedate = obj[i].released;
        var rating = obj[i].metacritic;
        var imgsrc = obj[i].background_image;
        var genres = "";
        for (var p = 0; p < obj[i].genres.length; p++) {
            genres += obj[i].genres[p].name;
            if (p != obj[i].genres.length - 1)
                genres += ", ";
        }
        var platforms = "";
        for (var p = 0; p < obj[i].platforms.length; p++) {
            platforms += obj[i].platforms[p].platform.name;
            if (p != obj[i].platforms.length - 1)
                platforms += ", ";
        }
        var stores = "";
        for (var p = 0; p < obj[i].stores.length; p++) {
            stores += obj[i].stores[p].store.name;
            if (p != obj[i].stores.length - 1)
                stores += ", ";
        }
        var tags = "";
        var counter = 0;
        for (var p = 0; p < obj[i].tags.length; p++) {
            if ((counter < 4) && (obj[i].tags[p].language == "eng")) { //Takes the first 4 eng tags.
                tags += obj[i].tags[p].name;
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
}

var featuredobj;
//fetured
function onFeaturedload() {
    hideFooter();
    const data = null;
    const req = new XMLHttpRequest();
    req.withCredentials = true;
    req.addEventListener("readystatechange", function () {
        if (this.readyState === this.DONE) {
            featuredobj = JSON.parse(this.responseText);
            populateFeatured(featuredobj);
            hideLoad();
            showFooter();
        }
    });
    req.open("GET", "https://free-to-play-games-database.p.rapidapi.com/api/filter?tag=action");
    req.setRequestHeader("x-rapidapi-key", "e25b776e64mshee562e432cc9115p1dcda5jsn47748f35359b");
    req.setRequestHeader("x-rapidapi-host", "free-to-play-games-database.p.rapidapi.com");
    req.send();
}

function populateFeatured(obj) {
    console.group("Featured Load");
    console.log(obj);
    var small = 0;
    
    var pos = obj.length + 1;//starts at last card to avoid overlaps in card names, would be array length +1 if importing whole array
    for (var i = parseInt(obj.length / 2); i < parseInt(obj.length / 2) + 15; i++) {
        $("#featuredMainpage").append('<div class="smallcard" id="smallcard' + pos + '"></div>');
        for (var p = 0; p < 3; p++) {
            var name = obj[i + p].title;
            var releasedate = obj[i + p].release_date;
            var developer = obj[i + p].developer;
            var genre = obj[i + p].genre;
            var platforms = obj[i + p].platform;
            var imgsrc = obj[i + p].thumbnail;
            var desc = obj[i].short_description;
            var rating = "";
            var tempname = name.replace(/\s/g, '-');
                    //GET SYSREQ. WITH REQUEST:
                    try {
                        var temp;
                        var req = new XMLHttpRequest();
                        req.onreadystatechange = function() {
                            if(this.readyState == 4 && this.status == 200) {
                                temp = JSON.parse(this.responseText);
                            }
                        };
                        req.open("GET", 'https://api.rawg.io/api/games/' + tempname + '?&key=114d98eeb30f4a67ae8e42a8eca9240d&dates=2019-09-01,2019-09-30&platforms=18,1,7', false);
                        req.send();
                    }
                    catch (e) {
                    }
            console.log(temp);
            if (temp != null) {
                if (temp.metacritic != null) {
                    rating = temp.metacritic;
                }   
                else rating = "not found";
            }
            else rating="not found";
            temp = null;
            //cards here
            $("#smallcard" + pos).append('<div class="gamecard" id="gamecard' + i+p + '"></div>');
            $("#gamecard" + i+p).append ('<div class="gameimage" id="gameimage' + i+p + '"></div>');
            $("#gameimage" + i+p).append('<div class="gameimage tooltip" id="tooltip' + i+p + '"></div>');
            $("#gameimage" + i+p).append('<h1 id="tipheader" style="text-align: center">' + name + '</h1>');
            $("#gameimage" + i+p).append('<img src="' + imgsrc + '"></img>');
            $("#gameimage" + i+p).append('<div class="titleblock" id="titleblock' + i+p + '"></div>');
            $("#titleblock" + i+p).append('<h1 id="releasedate">' + releasedate + '</h1>');
            $("#gameimage" + i+p).append('<div class="metadata" id="metadata' + i+p + '"></div>');
            $("#metadata" + i+p).append('<table class="data" id="data' + i+p + '"></table>');
            $("#data" + i+p).append("<tr>");
            $("#data" + i+p).append('<td colspan=2 style="text-align: justify">' + desc + '</td>');
            $("#data" + i+p).append("</tr>");
            $("#data" + i+p).append("<tr>");
            $("#data" + i+p).append("<th>Developers&colon;</th>");
            $("#data" + i+p).append('<td>' + developer + '</td>');
            $("#data" + i+p).append("</tr>");
            $("#data" + i+p).append("<tr>");
            $("#data" + i+p).append("<th>Genre/s&colon;</th>");
            $("#data" + i+p).append('<td>' + genre + '</td>');
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
}

//SEARCHING TRENDING
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
        var cname = trendobj.results[i].name;
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
                    for (var p = 0; p < trendobj.results[i].genres.length; p++) {
                        genres += trendobj.results[i].genres[p].name;
                        if (p != trendobj.results[i].genres.length - 1)
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

function searchTopRated() {
    $( ".gamecard" ).each(function(i) {
        i = i + 10;
        var cname = topratedobj.results[i].name;
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
                    for (var p = 0; p < topratedobj.results[i].genres.length; p++) {
                        genres += topratedobj.results[i].genres[p].name;
                        if (p != topratedobj.results[i].genres.length - 1)
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
            i = i + 100;
            var cname = newreleaseobj[i].title;
            cname = cname.toLowerCase();
            console.log(cname);
            var term = document.getElementById("textsearch").value;
            if (term != null) {
                term = term.toLowerCase();
                var filter = document.getElementById("filterNewReleases").value;
                console.log(filter);
                if (cname.includes(term)) {
                    if (filter != null) {
                        var genres = newreleaseobj[i].genre;
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
            i = i + parseInt(featuredobj.length / 2);
            var cname = featuredobj[i].title;
            cname = cname.toLowerCase();
            console.log(cname);
            var term = document.getElementById("textsearch").value;
            if (term != null) {
                term = term.toLowerCase();
                var filter = document.getElementById("filterFeatured").value;
                console.log(filter);
                if (cname.includes(term)) {
                    if (filter != null) {
                        var genres = featuredobj[i].genre;
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


//FOUND/NOT FOUND
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

/////////////////////////////////////
//CALENDER RELATED

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
    if (showingMonth == 12) {
        showingYear++;
        showingMonth = 1;
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
/////////////////////////////////////