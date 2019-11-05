# Nox-Decomp

**Note**, Nox-Decomp requires an original copy of Nox. None of the Nox game assets are provided by this project. To get a legitimate copy of the game assets, please refer to the [GoG release of Nox](https://www.gog.com/game/nox).


The original code comes from the [playnox.xyz](playnox.xyz) website. A copy of the original source code is permanently archived [here](https://web.archive.org/web/20191104220905/https://playnox.xyz/public_v1.zip). The code had some small modification to run it in Linux.

# Building from source

```
cd build
cmake ..
cmake --build . -j $(nproc)
```

# Running the game

```
innoextract setup_nox_2.0.0.20.exe
mv app/* .
./src/out
```

# Screenshots

# Known issues

* [ ] "Solo" game fails to start ("This game is only available in a primary installation")
* [ ] All graphics are totally corrupted in 8-bit color mode.
* [ ] Pointer is corrupted in 16-bit color mode.
* [ ] Crashes at exit.

# License

Regarding this code, the author [indicated that](https://www.reddit.com/r/linux_gaming/comments/cknh3l/play_nox_2000_in_a_browser_opensource_but/evrnrjh/):

> I would not consider this to be FOSS (free and open-source software). My goal was to show that this type of effort is now possible with modern tools. Also, for context, Nox has been abandoned by its creators and only runs on modern Windows thanks to community patches.

Following the [devilution](https://github.com/diasurgical/devilution) project, I think Public Domain is the best license for this.

# F.A.Q.

> Wow, does this mean I can download and play Nox for free now?

No, you'll need access to the data from the original game. If you don't have an original CD then you can [buy Nox from GoG.com](https://www.gog.com/game/nox). 

> Is Nox-Decomp even legal?

That's a tricky question. Under the DMCA, reverse-engineering has exceptions for the purpose of documentation and interoperability. Nox-Decomp provides the necessary documentation needed to achieve the latter. However, it falls into an entirely gray area. The real question is whether or not  Electronic Arts deems it necessary to take action.

# Credits
- Westwood Studios
- [/u/awesie](https://www.reddit.com/u/awesie)
- neuromancer (for some Linux fixes)

Are you the one that should be mentioned here? Let me know I will add your name. Also, if you are interested in continue this project, I can give you administrative access to this repository.

# Legal
Nox-Decomp is released to the Public Domain. The documentation and function provided by Nox-Decomp may only be utilized with assets provided by ownership of Nox.

Nox™ (C) 2000 Electronic Arts Inc.  All rights reserved. Nox are trademarks or registered trademarks of Electronic Arts in the U.S. and/or other countries.

Nox-Comp and any of its' maintainers are in no way associated with or endorsed by Electronic Arts.
