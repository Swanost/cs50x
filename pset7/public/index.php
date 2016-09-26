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
    // dump($showcash);
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "showcash" => $showcash, "title" => "Portfolio"]);

?>
