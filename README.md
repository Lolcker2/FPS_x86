# tk

tk is a game similar to Doom 2, or wolfenstein 3D.

this project has 2 parts:
- the first one being a game engine so tk could be run, the game engine uses RayCasting in order to deliver the illusion of 3D space
- the second one being the game itself (tk)

tk is a level based game, where you must go through the whole level in order to progress to the next one, though you can think of tk as a game where you must treverse the narrow, but long world, and there are check points along the way.

Let me explain:

![WhatsApp Image 2022-05-13 at 5 47 09 PM](https://user-images.githubusercontent.com/61828051/168308994-da705561-5378-4f80-9a15-308c7183bf04.jpeg)

- Black-> out line of each individual level 
- purple-> doorways / pathways between levels
- while-> the outline of the whole world

_you can treat the game with respect to the black borders (each level).
or treat it with respect to the white outline (the whole world), an acknowledge that the purple doorways act like checkpoints_


</br>
</br>
</br>

**The gameplay loop would go somthing like:**

- Treverse the map
- Watch out for enemys
- Found one, shoot it
- And remember to watch your back...


</br>
</br>

tk hasn't been started yet, since im working on the game engine itself.

</br>
</br>

**Part B:**

</br>

- I chose this particular project becase of a video i really enjoy, that video talked about raycasting and i used to binge watch it,
i haven't seen it in a couple of year, but then it poped at my youtube feed, I was hit by all these nostalgic feelings that made me discard the old project, and start this one.

</br>

- The challanges I'v faced were many, mostly bugs.
I have planned the project, and didn't have any problems with algorithems.
I *did* have some problems with syntax,
but mostly bugs.

</br>

- I'm not done yet, as I said before, i haven't started working on tk, rather spent all my time working on the engine.
If I had more time, I'll finish debugging the engine, and make tk.

</br>
</br>



Let me walk you through the code:
the code is seperated into many files.

</br>
</br>

### utils.inc

</br>
 	this is the file where the general purpose procedures are implemented.
 </br>
 </br>
 sws
 
	
	
				
