const fs = require("fs");

const input = fs.readFileSync("input.txt", "utf-8");
const pairs = input.split("\n");

let overlappingPairs = 0;
let overlapping2 = 0;
pairs.forEach(pair => {
    let sections = pair.split(",");
    let section1 = {
        from: parseInt(sections[0].split("-")[0]),
        to: parseInt(sections[0].split("-")[1])
    }
    let section2 = {
        from: parseInt(sections[1].split("-")[0]),
        to: parseInt(sections[1].split("-")[1])
    }

    if(section1.from >= section2.from && section1.to <= section2.to) {
        console.log("S1 contains S2", section1, section2);
        overlappingPairs++;
    }else if(section2.from >= section1.from && section2.to <= section1.to) {
        console.log("S2 contains S1", section1, section2);
        overlappingPairs++;
    }

    if(section1.from <= section2.to && section1.to >= section2.from) {
        overlapping2++;
    }
})

console.log("Answer 1: ", overlappingPairs);
console.log("Answer 2: ", overlapping2);
