function signup_click() {
    var name = document.getElementById("name").value;
    var surname = document.getElementById("surname").value;
    var email = document.getElementById("email").value;
    var pass1 = document.getElementById("password1").value;
    var pass2 = document.getElementById("password2").value;
    //console.log(name, surname, email, pass1, pass2);

    if (!filledin(name, surname, email, pass1, pass2)) {
        alert("Complete all fields before submitting.");
        return;
    }

    if (!matchpass(pass1, pass2)) {
        alert("Passwords do not match.");
        return;
    }

    if (!regex_email(email)) {
        alert("Email is not valid.")
        return;
    }

    if (!regex_password(pass1)) {
        alert("Password must contain:\n-one lowercase\n-one uppercase\n-one digit\n-one special character");
        return;
    }

    document.signupform.submit();

}

function regex_password(pass) {
    var reg=/^((?=.*\d)|(?=.*\W+))(?=.*[A-Z])(?![.\n])(?=.*[a-z]).{8,}$/;
    return pass.match(reg);
}

function regex_email(email) {
    var reg = /(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\])/;
    return email.match(reg);
}

function matchpass(p1, p2) {
    return p1 == p2;
}

function filledin(name, surname, email, p1, p2) {
    if (name == "")
        return false;
    if (surname == "")
        return false;
    if (email == "")
        return false;
    if (p1 == "")
        return false;
    if (p2 == "")
        return false;
    return true;
}