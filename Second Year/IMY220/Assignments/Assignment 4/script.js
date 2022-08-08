$(() => {
    $("button").on("click", function(){
        var id = $("button").index(this) + 1;
        var button = $("body div.row div.col > div:nth-child(" + id + ") button");
        if (button.html() == "Update") {
            var target = $("body div.row div.col > div:nth-child(" + id + ")");
            var input = $("body div.row div.col > div:nth-child(" + id + ") input");
            var newVal = input.val();
            input.remove();
            var b = $("body div.row div.col > div:nth-child(" + id + ") b");
            var span = $("body div.row div.col > div:nth-child(" + id + ") span");
            b.toggle();
            span.toggle();
            span.html(newVal);
            button.html("Edit");
            button.unwrap();
            target.removeClass("d-flex");
        } else {
            var target = $("body div.row div.col > div:nth-child(" + id + ")");
            var b = $("body div.row div.col > div:nth-child(" + id + ") b");
            var span = $("body div.row div.col > div:nth-child(" + id + ") span");
            var type = target.attr('data-type');
            var value = $("body div.row div.col > div:nth-child(" + id + ") span").text();
            b.toggle();
            span.toggle();
            target.prepend('<input class="form-control col-8" style="margin: 0px !important" type="' + type + '" value="' + value + '"></input>');
            button.html("Update");
            target.addClass("d-flex");
            button.wrap('<div class="col-4 p-0"></div>');
        }
    });

    
});