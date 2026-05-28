const express = require("express");
const fs = require("fs");
const path = require("path");

const app = express();

app.get("/", (req, res) => {
    res.send(`
        <h1>OS API</h1>

        <h2>Operating System Labs</h2>

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

        <h2>DAA Labs</h2>

        <ul>
            <li>/labz/dijkstra</li>
            <li>/labz/kruskal</li>
            <li>/labz/prims</li>
            <li>/labz/quicksort</li>
            <li>/labz/mergesort</li>
            <li>/labz/nqueen</li>
            <li>/labz/topological</li>
            <li>/labz/sumofsubsets</li>
            <li>/labz/lcs</li>
            <li>/labz/mcm</li>
            <li>/labz/horsepool</li>
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

    if (!fs.existsSync(filePath)) {
        return res.status(404).json({
            success: false,
            error: "File not found"
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

app.get("/labz/:name", (req, res) => {
    const name = req.params.name;

    const filePath = path.join(
        process.cwd(),
        "labz",
        `${name}.c`
    );

    if (!fs.existsSync(filePath)) {
        return res.status(404).json({
            success: false,
            error: "File not found"
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
    console.log(`OS API running on port ${PORT}`);
});