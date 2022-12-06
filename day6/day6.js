const fs = require("fs");
function checkIfDuplicateExists(arr) {
    return new Set(arr).size !== arr.length
}
const input = fs.readFileSync("input.txt", "utf-8");

let markerSize = 14;
let i = 0;
for(i = 0; i < input.length - 4; i++) {
    let marker = "";
    for(var m = 0; m < markerSize; m++) marker += input[i+m];
    console.log(marker);
    if(!checkIfDuplicateExists(marker)) {
        break;
    };
}
console.log(i+markerSize);