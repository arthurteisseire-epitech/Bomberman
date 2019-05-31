#!/bin/bash
sed -i 's/MAW_normal.png/assets\/PlayerA\/MAW_normal.png/g' walking/*.mtl
sed -i 's/MAW_diffuse.png/assets\/PlayerA\/MAW_diffuse.png/g' walking/*.mtl
sed -i 's/maria_specular.png/assets\/PlayerA\/maria_specular.png/g' walking/*.mtl
sed -i 's/MAW_normal.png/assets\/PlayerA\/MAW_normal.png/g' idle/*.mtl
sed -i 's/MAW_diffuse.png/assets\/PlayerA\/MAW_diffuse.png/g' idle/*.mtl
sed -i 's/maria_specular.png/assets\/PlayerA\/maria_specular.png/g' idle/*.mtl
