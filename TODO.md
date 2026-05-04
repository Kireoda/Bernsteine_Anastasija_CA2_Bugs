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
- [ ] Create `Teleporter.h` / `Teleporter.cpp`
- [ ] Inherit from Bug
- [ ] Implement `move()`:
    - [ ] Random (x,y) within board
    - [ ] Record path
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
- [x] Allocate using `new`
- [x] Store in vector
### Memory Management
- [x] Implement function to delete all bugs
- [ ] Ensure no memory leaks
---
## 5. Menu System (8 Options)
- [ ] 1. Initialize – clear + reload from file
- [x] 2. Display all bugs
- [ ] 3. Find a bug
- [ ] 4. Tap board
- [ ] 5. Life history
- [ ] 6. Display all cells
- [ ] 7. Run simulation
- [ ] 8. Exit
---
## 6. Display Features
### Display All Bugs (Feature 2)
- [ ] Show:
    - [ ] ID
    - [ ] Type (Crawler / Hopper / Teleporter)
    - [ ] Position
    - [ ] Direction (as text, not number)
    - [ ] Health
    - [ ] Alive/Dead
    - [ ] hopLength (if Hopper)
### Find Bug (Feature 3)
- [ ] Input ID
- [ ] Search vector
- [ ] Show details or “not found”
---
## 7. Movement System (Feature 4)
### Tap Board
- [ ] Select **one random alive bug → freeze it**
- [ ] Loop all bugs:
    - [ ] Skip dead bugs
    - [ ] Skip frozen bug
    - [ ] Call `move()`
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
- [ ] Build 10x10 grid
### After each tap:
- [ ] Rebuild cell map
- [ ] Only include alive bugs
### Display Cells
- [ ] Loop all cells (0–9, 0–9)
- [ ] Print:
    - empty
    - OR list of bugs (type + id)
---
## 10. Fight / Eat System (Feature 8)
- [ ] Group bugs by cell:
  `map<pair<int,int>, vector<Bug*>>`
- [ ] For each cell with ≥2 bugs:
    - [ ] Shuffle bugs randomly
    - [ ] Pair them (1v1)
### Fight Logic
- [ ] Each fight = 3 rounds
- [ ] Each round:
    - [ ] Both take random damage (0–5)
- [ ] If health ≤ 0:
    - [ ] Set alive = false
    - [ ] Record killer ID
- [ ] If odd number → last bug survives
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
- [ ] Generate filename:
  `bugs_life_history_date_time.out`
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