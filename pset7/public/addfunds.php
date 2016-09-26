<?php

    // configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("addfunds_form.php", ["title" => "Add Funds"]);
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["fund"] < 0)
        {
        apologize("Funds cannot be a negative number.");
        }
    
    $boostcash = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["fund"], $_SESSION["id"]);
    
    render("addfunds_view.php", ["title" => "Add Funds"]);
    }