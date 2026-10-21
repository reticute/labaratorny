'use strict'

function sumFor(...args) {
    let s = 0
    for (let i = 0; i < args.length; i++) s += args[i]
    return s
}

function sumForOf(...args) {
    let s = 0
    for (const x of args) s += x
    return s
}

function sumWhile(...args) {
    let s = 0
    let i = 0
    while (i < args.length) {
        s += args[i]
        i++
    }
    return s
}

function sumDoWhile(...args) {
    let s = 0
    let i = 0
    if (args.length === 0) return 0
    do {
        s += args[i]
        i++
    } while (i < args.length)
    return s
}

function sumReduce(...args) {
    return args.reduce((acc, x) => acc + x, 0)
}

const For = sumFor(1, 2, 3)
const ForOf = sumForOf(0)
const While = sumWhile()
const DoWhile = sumDoWhile(1, -1, 1)
const Reduce = sumReduce(10, -1, -1, -1)

console.log(For, ForOf, While, DoWhile, Reduce)