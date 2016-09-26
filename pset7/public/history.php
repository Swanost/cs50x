<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    $positions = [];
    foreach ($rows as $row)
    {
            $positions[] = [
                "transaction" => $row["transaction"],
                "time" => $row["time"],
                "symbol" => $row["symbol"],
                "shares" => $row["shares"],
                "price" => $row["price"]
            ];
    }
    // dump($showcash);
    // render portfolio
    render("history_view.php", ["historytable" => $positions, "title" => "History"]);

?>
