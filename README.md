# The-7-Wonders
A simple application designed around building wonders before time runs out.

## Version 1.0
### Future Changes
- Add additional characters.
### Fixes
- Every time you answer a question an entirely new prompt pops up.
- Upon building a wonder, the wonder menu does not reappear.

- cin.ignore now doubling second answer.
- certain answers reappearing
- adjust the percentages on stats
### Potential Changes
- Points to modify stats at game start, perhaps with two random options of what to increase.
- Modifier points have increasing costs the higher the stat.


## VERSION 1.1
### Changes
- Bonuses from completed wonders. Name and bonus appears at side of screen when complete. Either gives a stat boost, or a permanent unique question.
- Wonders now have a third requirement, usually luxuries, science, food, or faith.
- Wonders also should denote their cost at the select screen.
- Leader chooses religion at game start (Each one changes how temples work).
- Can build structures that last for a few turn and either give a steady supply of resources or temporary stat boosts.
### Advisors
- At all times can hire a governor, engineer, and/or consort to give various stat buffs.
- Each are part of a randomized pool that they are selected from at the start of the game.
- Once purchased they give a unique question in their question slot that is permanent.
### Future Resources
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
### Future Stats & Stat Changes:
- Old Stats: Intelligence:
    - Used to determine science gain & wood.
- Old Stats: Leadership:
    - Used to buy advisors & increases stone gain.
- New Stats: Belief:
    - Increases faith gain.
- New Stats: Fertility:
    - Increases food gain.
