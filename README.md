# Warehouse Management System (C++)

Console application that manages a warehouse supplying car components (motors and transmission trees) to car manufacturers. Built for the course **Industrial Informatics I** at Universidad Carlos III de Madrid (spring 2026), in a team of two.

## Features

- **Three user roles**, each with its own menu, all derived from an abstract `User` class (`menu()` is pure virtual):
  - **Admin**: register, modify, delete and list users.
  - **Manager**: manage the component catalogue, see active orders, request manufacturing of new units, search components by type.
  - **Client**: place, modify and cancel orders, add funds to the wallet, browse the catalogue and see order history.
- **Polymorphic component catalogue**: `Motor` (horsepower, efficiency) and `TransmissionTree` (gears, manual/automatic) derive from an abstract `Components` class.
- **Order processing**: the final price is checked against the client's wallet and stock is checked for every component. If stock is short, the order stays active until it can be completed. Cancelling refunds the full cost.
- **Time-based simulation**: on start-up the program reads the current date, works out how many units each manufacturing request has produced since it was logged (requests run one after another, and leftover time carries over to the next), updates the stock, then tries to complete pending orders.
- **Persistence**: users, components, manufacturing requests and orders are saved to text files on exit and loaded again on start-up.

## Class structure

```
User (abstract)              Components (abstract)
 ├── Admin                    ├── Motor
 ├── Manager                  └── TransmissionTree
 └── Client

System ── UserList, ComponentsList, ManufacturingRequestList, Date
Client ── OrdersList ── Order ── (Components*, units)
```

## Build and run

Requires a C++11 compiler and CMake.

```bash
mkdir build && cd build
cmake ..
cmake --build .
./proyectoAnayJorge
```

Or without CMake:

```bash
g++ -std=c++11 *.cpp -o warehouse
./warehouse
```

On first run there are no data files yet, so a default admin is created (user `admin`, password `1234`).

## Known limitations

This is the version submitted in May 2026. Known issues I plan to fix:

- Pending orders are checked per client, not globally from oldest to newest.
- No exception handling and no `<<` / `>>` operator overloads yet.
- Menus loop forever if standard input is closed.

## Authors

Jorge Tarriño (main developer) and Ana, Universidad Carlos III de Madrid.
