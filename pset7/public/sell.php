<?php

    // configuration
    require("../includes/config.php");

    $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $positions = [];
    $showcash = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => ($stock["price"] * $row["shares"])
            ];
        }
    }
    
    foreach ($cash as $money)
    {
        $showcash[] = [
            "cash" => $money["cash"]
        ];
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
    // dump($showcash);
    // render portfolio
    render("sell_form.php", ["positions" => $positions, "showcash" => $showcash, "title" => "Sell"]);
    }
    
     
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        $sellshares = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $stock["symbol"]);
        $updatecash = CS50::query("UPDATE users SET cash = cash + 1000 WHERE id = ?", $_SESSION["id"]);
        $sellstock = CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $stock["symbol"]);
        // dump($sellshares[0]);
        $sellhistory = CS50::query("INSERT INTO history (user_id, transaction, symbol, shares, price) VALUES(?, 'SELL', ?, ?, ?)", $_SESSION["id"], $stock["symbol"], $sellshares[0]["shares"], $stock["price"]);
        render("sell_view.php", ["title" => "Sold"]);
    }

?>