const fs = require("fs");

let stacks = [
    ['Q', 'W', 'P', 'S', 'Z', 'R', 'H', 'D'],
    ['V','B','R','W','Q','H','F'],
    ['C','V','S','H'],
    ['H','F','G'],
    ['P','G','J','B','Z'],
    ['Q','T','J','H','W','F','L'],
    ['Z','T','W','D','L','V','J','N'],
    ['D','T','Z','C','J','G','H','F'],
    ['W','P','V','M','B','H'],
]

const input = fs.readFileSync("input.txt", "utf-8");
const operations = input.split('\n');

operations.forEach(operation => {
    let para = operation.match(/\d+/g);
    let removedElement = []
    for(var i = 0; i < para[0]; i++) {
        removedElement.push(stacks[para[1]-1].pop());
    }
    removedElement.reverse(); //When reversed answer two will be accomplished
    for(e of removedElement) stacks[para[2]-1].push(e);
});

for(stack of stacks) console.log(stack[stack.length - 1])