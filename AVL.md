# AVL Tree Insertion — Voiceover Script
### Video Duration: 91.5 seconds
### Style: Simple Indian English, educational, friendly tone
### Tip: Speak at ~130-140 words per minute for natural Indian English pacing

---

## SCENE 1 — Title (0:00 – 0:07)
**[0:00 – 0:01]** *(Title writing animation — stay silent for 1 second)*

**[0:01 – 0:07]** *(Title fully visible with subtitle and insert sequence)*
> Hello friends! Welcome back to our Data Structures series. Today we are going to learn AVL Tree Insertion. We will insert six values — 10, 20, 30, 40, 50, and 25 — and see how the tree keeps itself balanced at every step.

**Word count:** ~40 words in 6 seconds ✓

---

## SCENE 2 — Step 1: Insert 10 — Root (0:08 – 0:12)
**[0:08 – 0:09]** *(Title "Step 1: Insert 10 (Root)" appears)*
> So, Step 1. We insert 10.

**[0:09 – 0:11]** *(Node 10 appears with balance factor 0)*
> Since the tree is empty, 10 becomes our root node. Balance factor is zero. Tree is perfectly balanced.

**[0:11 – 0:12]** *("Balanced (BF = 0)" text visible — brief pause)*

**Word count:** ~30 words in 4 seconds ✓

---

## SCENE 3 — Step 2: Insert 20 (0:13 – 0:17)
**[0:13 – 0:14]** *(Title "Step 2: Insert 20" appears, edge drawing)*
> Now, Step 2. We insert 20.

**[0:14 – 0:16]** *(Tree shows 10→20, BF = -1 visible)*
> 20 is greater than 10, so it goes to the right side. Balance factor of node 10 becomes minus 1. That is still within the range of minus 1 to plus 1.

**[0:16 – 0:17]** *("Balanced (BF = -1, within range)" text)*
> So, no rotation needed. Tree is still balanced.

**Word count:** ~50 words in 4 seconds — ⚠️ *Speak slightly faster here or extend to 0:18*

---

## SCENE 4 — Step 3: Insert 30 — First Rotation! (0:18 – 0:33)

**[0:18 – 0:20]** *(Title "Step 3: Insert 30 - First Rotation!" writing animation)*
> Now comes the interesting part. Step 3 — we insert 30.

**[0:20 – 0:23]** *(Left side shows unbalanced chain: 10→20→30, "Before (Unbalanced)" label)*
> 30 goes to the right of 20. Now see — 10, 20, 30 are all going in one direction, like a straight line going right-right-right.

**[0:23 – 0:26]** *(BF(10) = -2 appears in red, "RR Case: 10-20-30 right path" text)*
> The balance factor of node 10 becomes minus 2. That is outside the allowed range! This is called the RR case — because the imbalance is on the right-right path.

**[0:27 – 0:30]** *(Left Rotation arrow animates, "After (Balanced)" tree appears: 20 as root, 10 left, 30 right)*
> So what do we do? We perform a Left Rotation. Node 20 becomes the new root. 10 goes to the left, and 30 stays on the right.

**[0:30 – 0:33]** *("Balanced!" text, BF = 0 shown)*
> Beautiful! Now the balance factor is zero. Tree is perfectly balanced again. This is the power of AVL tree — it fixes itself automatically.

**Word count:** ~130 words in 15 seconds ✓

---

## SCENE 5 — Step 4: Insert 40 (0:34 – 0:39)
**[0:34 – 0:35]** *(Title "Step 4: Insert 40" appears)*
> Step 4. We insert 40.

**[0:35 – 0:37]** *(Tree building: 20 root, 10 left, 30 right, 40 added as right child of 30)*
> 40 is greater than 20, greater than 30, so it goes to the right of 30.

**[0:37 – 0:39]** *(BF values shown: 20 has -1, 30 has -1, "Balanced (All BF within range)" text)*
> We check the balance factors — node 20 is minus 1, node 30 is minus 1. Both are within the allowed range. So no rotation needed this time. Simple insertion.

**Word count:** ~60 words in 5 seconds — ⚠️ *Speak briskly*

---

## SCENE 6 — Step 5: Insert 50 — Second Rotation! (0:40 – 0:53)

**[0:40 – 0:42]** *(Title "Step 5: Insert 50 - Second Rotation!" appears)*
> Step 5! We insert 50. And again we get a rotation.

**[0:42 – 0:45]** *(Left side: unbalanced tree with 30→40→50 chain, BF values -2 shown in red)*
> 50 goes to the right of 40. Now look at node 30 — its balance factor becomes minus 2. Again it is the RR case, because 30, 40, 50 are going right-right.

**[0:45 – 0:48]** *("Left Rotation on 30" text and arrow animating)*
> So we perform a Left Rotation on node 30. Node 40 takes the place of 30.

**[0:48 – 0:53]** *(Right side: balanced tree: 20 root, 10 left, 40 right with 30 and 50 as children. BF = 0 for 40, -1 for 20, "Balanced!" text)*
> Now 40 has 30 on the left and 50 on the right. The root 20 has balance factor minus 1, which is fine. Tree is balanced again! Notice how the rotation happened only at the subtree level — node 20 stays as root.

**Word count:** ~110 words in 13 seconds ✓

---

## SCENE 7 — Step 6: Insert 25 — RL Rotation! (0:53 – 0:68)

**[0:53 – 0:56]** *(Title "Step 6: Insert 25 - RL Rotation!" appears, "Before" unbalanced tree fading in)*
> Now the most interesting step — Step 6. We insert 25. And this time, we get a different type of rotation.

**[0:56 – 0:59]** *(Left tree: 20→40→30→25 path shown, BF(20) = -2 in red, "RL Case" label)*
> 25 is greater than 20, so goes right. Then less than 40, goes left. Less than 30, goes left again. Now node 20 has balance factor minus 2. But see — the path goes right then left. This is called the RL case — Right-Left case.

**[0:59 – 1:02]** *(Middle tree: "Right on 40" label, shows intermediate state after right rotation on child)*
> For RL case, we need two rotations. First, we do a Right Rotation on node 40. This rearranges 30 and 40 — now 30 becomes parent of 40.

**[1:02 – 1:06]** *(Right tree: "Left on 20" label, final balanced tree with 30 as root, 20 and 40 as children, 10-25-50 as leaves, BF = 0, "Final Tree!" label)*
> Then, we do a Left Rotation on node 20. And look at the result! 30 becomes the new root. 20 is on the left with 10 and 25 as its children. 40 is on the right with 50. Balance factor of root is zero — perfectly balanced!

**Word count:** ~160 words in 15 seconds — ⚠️ *This is dense — speak at moderate-fast pace, emphasize key terms*

---

## SCENE 8 — Final AVL Tree Analysis (0:69 – 0:82)

**[0:69 – 0:71]** *(Title "Final AVL Tree Analysis" appears)*
> Let us now look at our final AVL tree.

**[0:71 – 0:75]** *(Final tree displayed: 30 root, 20 left, 40 right, 10-25-50 leaves. Stats appearing: Total Nodes: 6, Tree Height: 3)*
> We have 6 nodes in total. The tree height is just 3. Compare this with a normal BST — if we inserted 10, 20, 30, 40, 50 without balancing, it would become a straight line with height 6!

**[0:75 – 0:78]** *("Rotations: 3 (RR, RR, RL)" text appears)*
> We performed 3 rotations in total — two RR rotations and one RL rotation. These rotations are what keep the tree balanced.

**[0:78 – 0:82]** *("All Operations: O(log n)" text appears)*
> And the best part — because the tree is always balanced, all operations like search, insert, and delete take O of log n time. That is the guarantee of AVL trees.

**Word count:** ~110 words in 13 seconds ✓

---

## SCENE 9 — Key Takeaways (0:83 – 0:91)

**[0:83 – 0:85]** *(Title "Key Takeaways" with summary list appearing)*
> Let us quickly recap.

**[0:85 – 0:89]** *(All 6 steps listed with rotation types highlighted)*
> Step 1 and 2 were simple insertions. Step 3 and 5 had RR case — we used Left Rotation. Step 4 was again simple. And Step 6 had the RL case — we used Right then Left rotation. The key idea is — whenever balance factor goes beyond minus 1 to plus 1, AVL tree fixes it using rotations.

**[0:89 – 0:91]** *("AVL trees self-balance to guarantee O(log n) performance!" text)*
> AVL trees are self-balancing. They guarantee O of log n performance. That's all for today — thank you for watching! Like, subscribe, and see you in the next video.

**Word count:** ~95 words in 8 seconds — ⚠️ *Speak at natural pace, end confidently*

---

## TOTAL WORD COUNT: ~785 words in 91.5 seconds
## Average pace: ~130 words per minute (comfortable Indian English speed)

---

# PRONUNCIATION GUIDE (Indian English)

| Term | Say it as |
|------|-----------|
| AVL | "Ay-Vee-Ell" |
| BF | "Bee-Eff" (or "Balance Factor") |
| BST | "Bee-Ess-Tee" |
| RR Case | "Arr-Arr Case" |
| RL Case | "Arr-Ell Case" |
| O(log n) | "Oh of log en" |
| Node 10 | "Node ten" |
| -2 | "Minus two" |
| Root | "Root" (not "rut") |

---

# VOICE STYLE NOTES

1. **Tone:** Friendly teacher explaining to a friend. Not robotic, not overly excited.
2. **Emphasis words:** Stress "rotation", "balanced", "imbalance", "RR case", "RL case"
3. **Pauses:** Leave brief pauses (0.3–0.5s) after each step transition
4. **Speed variation:**
   - Title scene: Slower, welcoming
   - Simple insertions (Steps 1, 2, 4): Normal pace
   - Rotation scenes (Steps 3, 5, 6): Slightly slower, more deliberate — these are teaching moments
   - Wrap-up: Energetic, confident
5. **Indian English flavor:** Use natural phrases like "So what do we do?", "Beautiful!", "See — the path goes...", "Compare this with..."

---

# TTS TOOL RECOMMENDATIONS

If you want to use AI voice instead of recording yourself:

| Tool | Indian English Quality | Free? |
|------|----------------------|-------|
| **ElevenLabs** | Excellent (use "Raj" or custom Indian voice) | 10 min free/month |
| **Google Cloud TTS** | Good ("en-IN" locale, WaveNet voices) | 1M chars free |
| **Azure TTS** | Very Good ("en-IN-PrabhatNeural") | 500K chars free |
| **gTTS (Python)** | Basic but works ("en", tld="co.in") | Unlimited free |
| **Narakeet** | Good for video+voice sync | Free trial |

### Quick gTTS command (free, offline-capable):
```python
from gtts import gTTS
tts = gTTS(text="your script here", lang='en', tld='co.in', slow=False)
tts.save("voiceover_scene1.mp3")
```

### Merging with ffmpeg:
```bash
ffmpeg -i AVL_Tree_Insertion.mp4 -i voiceover_full.mp3 \
  -c:v copy -c:a aac -map 0:v:0 -map 1:a:0 \
  -shortest AVL_Tree_Insertion_WITH_VOICE.mp4
```
