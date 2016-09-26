<?php

    // configuration
    // require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
       
            print("Name: " . $stock["name"] . " ");
            print("Symbol: " . $stock["symbol"] . " ");
            print("Price: " . number_format($stock["price"], 2) . " ");
    }
?>