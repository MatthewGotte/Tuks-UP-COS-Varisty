function login_click() {
    var email = document.getElementById("email").value;
    var password = document.getElementById("password").value;
    if (!filledin(email, password)) {
        alert("Complete all fields before submitting.");
        return;
    }
    document.loginform.submit();
}

function filledin(email, p1) {
    if (email == "")
        return false;
    if (p1 == "")
        return false;
    return true;
}