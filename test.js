const person = {
    Имя : {
        И: 'Bob',
        Ф: 'Mayer'
    },
    age: 25
}

const person2 = JSON.parse(JSON.stringify(person))

person2.Имя.И = 'alice'

function repeat (person,person2){
console.log(person2)
console.log(person)
}

repeat(person2)