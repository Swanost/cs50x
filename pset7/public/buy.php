<?php

    // configuration
    require("../includes/config.php");
    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $showcash = [];
    foreach ($cash as $money)
    {
        $showcash[] = [
            "cash" => $money["cash"]
        ];
    }
    $availablecash = $showcash[0]["cash"];
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]) || empty($_POST["shares"]))
        {
            apologize("Please fill in both fields.");
        }
        
        else
        {
            $stock = lookup($_POST["symbol"]);
            
            if (!$stock)
            {
                apologize("This is an invalid symbol.");
            }
            
            if(preg_match("/^\d+$/", $_POST["shares"]))
            {
                if($stock["price"] * $_POST["shares"] < $availablecash)
                {
                    $buy = CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $stock["symbol"], $_POST["shares"]);
                    $totalprice = ($stock["price"] * $_POST["shares"]);
                    // dump($totalprice);
                    $updatecash = CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $totalprice, $_SESSION["id"]);
                    $buyhistory = CS50::query("INSERT INTO history (user_id, transaction, symbol, shares, price) VALUES(?, 'BUY', ?, ?, ?)", $_SESSION["id"], $stock["symbol"], $_POST["shares"], $stock["price"]);
                    render("buy_view.php", ["title" => "Bought"]);
                }
                
                else
                {
                    apologize("Not enough cash on hand.");
                }
            }
            
            else
            {
                apologize("Invalid entry.");
            }
        }
    
    }
?>
