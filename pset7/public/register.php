<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide a username.");
        }
        
        if (empty($_POST["password"]))
        {
            apologize("You must provide a password.");
        }
        
        if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Your entered passwords must match.");
        }
        
        
        $register = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        
        if ($register != 0)
        {
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
        
            // Build session and store ID        
            // session_start();
            $_SESSION["id"] = $id;
            header("Location: ./index.php");
            exit;
        }
        
        else
        {
            header("Location: ./login.php");
            exit;
        }
    }

?>