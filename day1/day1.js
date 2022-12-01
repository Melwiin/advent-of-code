const fs = require("fs");

const d = fs.readFileSync("input.txt", "utf-8");
const es = d.split("\n\n");
const c = [];

es.forEach(e => {
    let r = e.split("\n");
    let caa = 0;
    r.forEach(ca => {
        caa+=parseInt(ca);
    });
    c.push(caa);
})


let sorted = c.sort(function(a, b){return b-a});

console.log("Antwort 1: ", sorted[0]);
console.log("Antwort 2: ", sorted[0] + sorted[1] + sorted[2]);