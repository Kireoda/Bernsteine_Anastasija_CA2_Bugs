#  A Bug’s Life Project – Full TODO List
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
- [ ] Ensure no memory leaks
---
## 5. Menu System (8 Options)
- [x] 1. Initialize – clear + reload from file
- [x] 2. Display all bugs
- [x] 3. Find a bug
- [x] 4. Tap board
- [x] 5. Life history
- [x] 6. Display all cells
- [x] 7. Run simulation
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
- [x] Print:
    - [x] ID + type
    - [x] Full path
    - [x] Status:
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
- [x] While `countAlive() > 1`:
    - [x] Tap board
    - [x] Display progress
    - [x] Wait 1 second
- [x] Print final winner:
    - "Last Bug Standing: ID X"
---
## 12. File Output (Exit)
- [x] Generate filename: `bugs_life_history_date_time.out`
- [x] Write:
    - [x] ID
    - [x] Path
    - [x] Final status (Alive / Eaten by X)
---
## 13. Utility Functions
- [x] Move `buildCellMap()` from `public` to `private` in Board.h (no internal pointers exposed)
- [x] Delete copy constructor and assignment operator for Board (`= delete`) to avoid shallow copying
- [x] Replace `rand()` for damage in fights with `std::uniform_int_distribution` (consistent with shuffle generator)
---
## 14. Testing & Edge Cases
- [x] Test file loading
- [x] Test edge movement (corners, walls)
- [x] Test hopper partial movement
- [x] Test fights (2, 3, 4+ bugs)
- [x] Ensure dead bugs:
    - [x] Don’t move
    - [x] Don’t fight
- [x] Use `addToPath()` inside Crawler, Hopper, Teleporter `move()` methods instead of `path.push_back` directly
- [x] Run Valgrind or AddressSanitizer (confirm zero memory leaks)
---
## 15. Code Quality
- [x] Use `vector<Bug*>` (not objects)
- [x] Separate `.h` and `.cpp`
- [x] Clean variable names
- [x] Avoid duplicate code (DRY)
- [x] Use `const` where possible
- [x] Add comments where needed
---
## 16. Deliverables
- [x] Screencast (≤5 min):
    - [x] App working
    - [x] Code walkthrough
    - [x] Say name + class
- [x] Zip project folder:
  `Lastname_Firstname_CA2_Bugs`
- [x] Zip file:
  `Lastname_Firstname.zip`
- [x] Include CA cover sheet (PDF)
- [x] Upload to Moodle before deadline
---