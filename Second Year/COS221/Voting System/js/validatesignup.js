function sign_click() {

    var name = document.signupform.fname.value;

    var surname = document.signupform.surname.value;

    var initials = document.signupform.initials.value;

    var id = document.signupform.id.value

    var email = document.signupform.email.value;

    var contact = document.signupform.contact.value;

    var address = document.signupform.address.value;

    var areacode = document.signupform.areacode.value;

    var password1 = document.signupform.password1.value;

    var password2 = document.signupform.password2.value;

    var all = true

    if (address == "") {
        printError("addrerror", "Please Enter address ");
        all = false;
    }
    if (address) {
        printError("addrerror", "");
    }

    if (initials == "") {
        printError("muerror", "Please Enter Initials");
        all = false;
    }
    if (initials) {
        printError("muerror", "");
    }
    if (areacode == "") {
        printError("arerror", "Please Enter areacode");
        all = false;
    }
    if (areacode) {
        printError("arerror", "");
    }
    if (id == "") {
        printError("ierror", "Please Enter ID");
        all = false;
    }
    if (id) {
        if (!validateID(id)) {
            printError("ierror", "Please Enter Valid ID");
            all = false;
        } else {
            printError("ierror", "");

        }

    }
    if (name == "") {
        printError("nerror", "Please Enter Name");
        all = false;
    }
    if (name) {
        printError("nerror", "");

    }
    if (surname == "") {
        printError("serror", "Please Enter Surname");
        all = false;
    }
    if (surname) {
        printError("serror", "");

    }
    if (email == "") {
        printError("eerror", "Please Enter email");
        all = false;

    }
    if (email) {
        if (!validateEmail(email)) {
            printError("eerror", "Please Enter Valid email");
            all = false;
        } else {
            printError("eerror", "");

        }
    }
    if (password1 == "") {
        printError("p1error", "Please Enter Password")
        all = false;
    }
    if (password1) {
        if (!validatePassword(password1)) {
            printError("p1error", "Please Enter Valid Password");
            all = false;
        } else {
            printError("p1error", "");
        }

    }
    if (password2 == "") {
        printError("p2error", "Please Enter Password");
        all = false;
    }
    if (password2) {
        if (password1 != password2) {
            printError("p2error", "Passwords Not Identical");
            printError("p1error", "Passwords Not Indential");
            all = false;

        } else if (!validatePassword(password2)) {
            printError("p2error", "Please Enter Valid Password");
            all = false;
        } else {
            printError("p2error", "");
        }

    }
    if (all === true) {
        return true;
    }

    return false;
};

function printError(elemId, hintMsg) {
    document.getElementById(elemId).innerHTML = hintMsg;
}

function validatePassword(password) {
    var re = /^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$ %^&*-]).{8,}$/;
    return re.test(password);
}

function validateEmail(email) {
    var re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return re.test(String(email).toLowerCase());
}

function validateID(id) {
    var re = /^([0-9][0-9])(([0][1-9])|([1][0-2]))(([0-2][0-9])|([3][0-1]))([0-9])([0-9]{3})([0-9])([0-9])([0-9])?/;
    return re.test(id);

}