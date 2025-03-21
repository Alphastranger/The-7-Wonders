# The-7-Wonders
A simple text application designed around building wonders before time runs out.

## Description
This project is a fairly straight forward text application accessed through the terminal. Run it like you would any other terminal application and you will get your first prompt, asking you to select your character by name. Mind your spelling. Following that you make your choice of wonder and try to accumulate enough resources to build that wonder before the timer, listed as "Days Left" in the top corner, runs out.
You will first notice the text box listing resources and stats. Stone is a resource gathered by answering various questions and the amount garnered is increased based on your leadership stat. Wood is similarly governed by Intelligence, and Gold by Cunning. Endurance dictates your energy, but at the end of each turn you gain a small bit of energy based on this stat, eventually snowballing as you build that endurance stat.
Below the resources and stats are a list of questions, the first three being pulled from a random set, while the rest are all unique. The fourth question is always the wonder question, providing resource requirements and, upon meeting them, allows you to progress to the next wonder or complete the game. The fifth question is unique to your character and is always accessible. The final question is a turn skip that gives energy should you find yourself at a loss.
Complete every wonder, and you have won the game! That easy.

![Starting Screen](images/Screenshot.png)

## Credits
[Jay Flynn](https://github.com/Alphastranger)

## Version Changes
### Version 1.0
#### Fixes
- Every time you answer a question an entirely new prompt pops up.
#### Potential Changes
- Points to modify stats at game start, perhaps with two random options of what to increase.
- Modifier points have increasing costs the higher the stat.


### Version 1.1
#### Changes
- Bonuses from completed wonders. Name and bonus appears at side of screen when complete. Either gives a stat boost, or a permanent unique question.
- Wonders now have a third requirement, usually luxuries, science, food, or faith.
- Wonders also should denote their cost at the select screen.
- Leader chooses religion at game start (Each one changes how temples work).
- Can build structures that last for a few turn and either give a steady supply of resources or temporary stat boosts.
#### Advisors
- At all times can hire a governor, engineer, and/or consort to give various stat buffs.
- Each are part of a randomized pool that they are selected from at the start of the game.
- Once purchased they give a unique question in their question slot that is permanent.
#### Future Resources
- New Resources: Luxuries:
    - Luxuries are used to get money or for certain wonder qualifications.
- New Resources: Faith:
    - Used to buy prophets and temples in conjunction with building resources.
    - Prophets provide temporary buffs (boolean that activates if statement to make them and their timer appear.)
    - Temples give flat bonuses to faith and whatever your religion is.
- New Resources: Food:
    - Drains every turn based on population size. If Food tries to dip below zero the population will start dying instead.
- New Resources: Population:
    - Larger population gives more of every resource. Can always be purchased for food and gold.
- New Resources: Science:
    - Can be used to buy philosophers.
    - Philosophers will increase a random stat after a few turns along with a message saying what increased.
#### Future Stats & Stat Changes:
- Old Stats: Intelligence:
    - Used to determine science gain & wood.
- Old Stats: Leadership:
    - Used to buy advisors & increases stone gain.
- New Stats: Belief:
    - Increases faith gain.
- New Stats: Fertility:
    - Increases food gain.

### Version 1.2
#### Changes
- Make wonders built slowly, contributing whatever you can to it.
- Add AI opponents who are also slowly getting resources and trying to build the wonders.
- Either have the race to be who finishes all seven, or who finishes the most by the end.
- To expand on that, if the AI or player builds a wonder it is no longer available and any resources spent building are lost.