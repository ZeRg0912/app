const person = {
    Имя : {
        И: 'Bob',
        Ф: 'Mayer'
    },
    age: 25
}

const person2 = JSON.parse(JSON.stringify(person))

person2.Имя.И = 'alice'

console.log(person2.Имя)
console.log(person.Имя)