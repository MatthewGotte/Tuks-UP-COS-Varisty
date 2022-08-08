const MultipleChecker = {
    
    isMultiple: function(x, y)  {
        return (x % y) == 0
    },

    fillArray: function(x, y)  {
        var output = [];
        y = Number(y);
        var temp = y;
        output.push(y);
        for (var i = 0; i < x; i++) {
            y += temp;
            output.push(y);
        }
        return output;
    }
}

var checkMultipleBtn = document.getElementById("checkMultipleBtn");
checkMultipleBtn.addEventListener("click", CheckIfMultiple);
function CheckIfMultiple() {
    var target = document.getElementById("multipleResult");
    var x = document.getElementById("multipleChecker").value;
    var y = document.getElementById("multiplicationTable1").value;
    target.innerHTML = MultipleChecker.isMultiple(x, y);
}

var checkMultipleBtn = document.getElementById("checkPangram");
checkMultipleBtn.addEventListener("click", checkPanagram_event);
function checkPanagram_event() {
    var target = document.getElementById("palindromeResult");
    var x = document.getElementById("palindromeChecker").value;
    target.innerHTML = checkPanagram(x);
}

function checkPanagram(s) {
    var list = 'abcdefghijklmnopqrstuvwxyz'.split("");
    var str = s.toString().toLowerCase();
    return list.every(x => str.includes(x));
}