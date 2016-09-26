<?php

    // configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol to lookup.");
        }
        
        else
        {
            $stock = lookup($_POST["symbol"]);
            if ($stock)
            {
                render("quote_view.php", ["title" => "Quote", "stock" => $stock]);   
            }
            else
            {
                apologize("This is an invalid symbol.");
            }
        }
    
    }
?>