<div id="middle">
    <form action="sell.php" method="POST"/>
        <fieldset>
            <div class="form-group">
                <option disabled selected value="">Symbol</option>
                    <select class="form-control" name="symbol">
                    <?php foreach ($positions as $position)
                    {
                        print("<option value ='" . $position["symbol"] . "'>" . $position["symbol"] . "</option>");
                    }
                    ?>
                    </select>
            </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
        </fieldset>
    </form>
</div>