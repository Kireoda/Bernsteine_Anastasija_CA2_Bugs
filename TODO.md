# 🐞 A Bug’s Life Project – Full TODO List
---
## 1. Setup & Version Control
- [x] Create project folder: `Lastname_Firstname_CA2_Bugs`
- [x] Create folder structure:  
- [x] `src/`  
- [x] `include/`  
- [x] `data/`  
- [x] `output/`
- [x] Initialise Git repository
- [x] Commit after EVERY feature (important for marks)
- [x] Create `data/bugs.txt` with sample data
---
## 2. Core Classes (Header + .cpp)
### Bug (Abstract Base Class)
- [x] Create `Bug.h` /`Bug.cpp`
- [x] Add protected members:  
- [x] id 
- [x] position (`pair<int,int>`)  
- [x] direction (use enum)  
- [x] health 
- [x] alive 
- [x] path (`list<pair<int,int>>`)
- [x] Add **pure virtual** `move() = 0`
- [x] Implement `isWayBlocked()`
- [x] Add constructor
- [x] Add getters (no direct access outside)
- [x] Add **virtual destructor**
- [x] Record **initial position in path**
## Direction Handling
- [x] Convert direction to string for display
---
## Crawler
- [x] Create `Crawler.h` / `Crawler.cpp`
- [x] Inherit from Bug
- [x] Implement `move()`:
    - [x] Move 1 step
    - [x] If blocked → random direction until valid
    - [x] Update position
    - [x] Record path
---
## Hopper
- [x] Create `Hopper.h` / `Hopper.cpp`
- [x] Add `hopLength`
- [x] Implement `move()`:
    - [x] Move `hopLength` steps
    - [x] If blocked → random direction
    - [x] Stop early if hitting edge
    - [x] Record path
---
## Teleporter (New Bug Type)
- [x] Create `Teleporter.h` / `Teleporter.cpp`
- [x] Inherit from Bug
- [x] Implement `move()`:
    - [x] Random (x,y) within board
    - [x] Record path
---
## 3. Board Class (Core System)
- [x] Create `Board.h` / `Board.cpp`
- [x] Store:
    - [x] `vector<Bug*> bugs` (inside Board, not main)
---
## 4. Data Management
### Load Bugs (Feature 1)
- [x] Read `bugs.txt`
- [x] Parse `;` delimited lines
- [x] Create correct object:
    - [x] C → Crawler
    - [x] H → Hopper
    - [x] T → Teleporter
- [x] Allocate using `new`
- [x] Store in vector
### Memory Management
- [x] Implement function to delete all bugs
- [x] Ensure no memory leaks
---
## 5. Menu System (8 Options)
- [x] 1. Initialize – clear + reload from file
- [x] 2. Display all bugs
- [x] 3. Find a bug
- [x] 4. Tap board
- [ ] 5. Life history
- [x] 6. Display all cells
- [ ] 7. Run simulation
- [x] 0. Exit
---
## 6. Display Features
### Display All Bugs (Feature 2)
- [x] Show:
    - [x] ID
    - [x] Type (Crawler / Hopper / Teleporter)
    - [x] Position
    - [x] Direction (as text, not number)
    - [x] Health
    - [x] Alive/Dead
    - [x] hopLength (if Hopper)
### Find Bug (Feature 3)
- [x] Input ID
- [x] Search vector
- [x] Show details or “not found”
---
## 7. Movement System (Feature 4)
### Tap Board
- [x] Select **one random alive bug → freeze it**
- [x] Loop all bugs:
    - [x] Skip dead bugs
    - [x] Skip frozen bug
    - [x] Call `move()`
---
## 8. Life History (Feature 5)
- [x] Track path for every bug
- [ ] Print:
    - [ ] ID + type
    - [ ] Full path
    - [ ] Status:
        - Alive
        - OR “Eaten by X”
---
## 9. Cell System (Feature 6)
- [x] Build 10x10 grid
### After each tap:
- [x] Rebuild cell map
- [x] Only include alive bugs
### Display Cells
- [x] Loop all cells (0–9, 0–9)
- [x] Print:
    - empty
    - OR list of bugs (type + id)
---
## 10. Fight / Eat System (Feature 8)
- [x] Group bugs by cell: `map<pair<int,int>, vector<Bug*>>`
- [x] For each cell with ≥2 bugs:
    - [x] Shuffle bugs randomly
    - [x] Pair them (1v1)
### Fight Logic
- [x] Each fight = 3 rounds
- [x] Each round:
    - [x] Both take random damage (0–5)
- [x] If health ≤ 0:
    - [x] Set alive = false
    - [x] Record killer ID
- [x] If odd number → last bug survives
---
## 11. Simulation (Feature 9)
- [ ] While `countAlive() > 1`:
    - [ ] Tap board
    - [ ] Display progress
    - [ ] Wait 1 second
- [ ] Print final winner:
    - "Last Bug Standing: ID X"
---
## 12. File Output (Exit)
- [ ] Generate filename: `bugs_life_history_date_time.out`
- [ ] Write:
    - [ ] ID
    - [ ] Path
    - [ ] Final status (Alive / Eaten by X)
---
## 13. Utility Functions
- [ ] `randomInt(min,max)`
- [ ] `randomDirection()`
- [ ] `countAlive()`
- [ ] `isPositionValid(x,y)`
- [ ] `getBugsOnCell()`
---
## 14. Testing & Edge Cases
- [x] Test file loading
- [x] Test edge movement (corners, walls)
- [ ] Test hopper partial movement
- [ ] Test fights (2, 3, 4+ bugs)
- [ ] Ensure dead bugs:
    - [ ] Don’t move
    - [ ] Don’t fight
- [ ] Run memory checker (Valgrind or sanitizer)
---
## 15. Code Quality (Marks!)
- [x] Use `vector<Bug*>` (not objects)
- [x] Separate `.h` and `.cpp`
- [ ] Clean variable names
- [ ] Avoid duplicate code (DRY)
- [ ] Use `const` where possible
- [ ] Add comments where needed
---
## 16. Deliverables
- [ ] Screencast (≤5 min):
    - [ ] App working
    - [ ] Code walkthrough
    - [ ] Say name + class
- [ ] Zip project folder:
  `Lastname_Firstname_CA2_Bugs`
- [ ] Zip file:
  `Lastname_Firstname.zip`
- [ ] Include CA cover sheet (PDF)
- [ ] Upload to Moodle before deadline
---