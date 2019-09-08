// Notes -- To Do
//
//
// PELLETS
//
// Once there's only a few left an excpetion is thrown in Pellets::Render()
// Currently pellets aren't being removed from the list of Pellets in Map, the instance is just being deleted.
// When trying to remove them from the list it instantly throws an exception in Map::PelletCollisions()
//
//
// GHOSTS
//
// Need to stagger leaving times from the ghost house
//
// If killed when frightened they respawn not frightened, if the player then eats another power up while ghosts are still frightened
// the respawned ghosts don't become frightened.
//
// Often the collisions aren't registering -- If colliding head on the player and ai are probably swapping spaces at the exact same 
// time meaning they never actually share a space thus according to the code, never actually 'collide'.
//
// UI
// 
// Add high score