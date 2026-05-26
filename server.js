const express = require("express");
const fs = require("fs");
const path = require("path");

const app = express();

app.get("/", (req, res) => {
    res.send(`
        <h1>OS Lab API</h1>

        <h3>Available Endpoints</h3>

        <ul>
            <li>/lab/lab1</li>
            <li>/lab/lab2a</li>
            <li>/lab/lab2b</li>
            <li>/lab/lab3</li>
            <li>/lab/lab4</li>
            <li>/lab/lab5</li>
            <li>/lab/lab6</li>
            <li>/lab/lab7</li>
            <li>/lab/lab8</li>
            <li>/lab/lab9</li>
        </ul>
    `);
});

app.get("/lab/:name", (req, res) => {
    const name = req.params.name;

    const filePath = path.join(
        process.cwd(),
        "labs",
        `${name}.c`
    );

    console.log("Trying:", filePath);

    if (!fs.existsSync(filePath)) {
        return res.status(404).json({
            success: false,
            error: "File not found",
            searched: filePath
        });
    }

    let code = fs.readFileSync(filePath, "utf8");

    code = code.replace(/\r\n/g, "\n");

    res.setHeader(
        "Content-Type",
        "text/plain; charset=utf-8"
    );

    res.send(code);
});

const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {
    console.log(`OS Lab API running on port ${PORT}`);
});