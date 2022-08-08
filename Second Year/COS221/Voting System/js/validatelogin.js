function sign_click() {
    var id = document.loginform.id.value;
    var password = document.loginform.password.value;

    var all = true;
    if (id == "") {
        printError("ierror", "Please Enter ID");
        all = false;
    }
    if (id) {

        printError("ierror", "");

    }
    if (password == "") {
        printError("perror", "Please Enter Password");
        all = false;
    }
    if (password) {
        printError("perror", "");
    }
    if (all === true) {
        return true;
    }

    return false;
}

function printError(elemId, hintMsg) {
    document.getElementById(elemId).innerHTML = hintMsg;
}