<div id="middle">
<table class="table table-striped">

    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>

    <tbody>
        <?php
    
        foreach ($historytable as $history)
        {
            print("<tr>");
            print("<td>" . $history["transaction"] . "</td>");
            print("<td>" . $history["time"] . "</td>");
            print("<td>" . $history["symbol"] . "</td>");
            print("<td>" . $history["shares"] . "</td>");
            print("<td>$" . $history["price"] . "</td>");
            print("</tr>");
        }

    ?>
    </tbody>
</table>
</div>