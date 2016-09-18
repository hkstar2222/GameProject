// ------------------------------------------------------------------------------
//  <autogenerated>
//      This code was generated by a tool.
//      Mono Runtime Version: 4.0.30319.1
// 
//      Changes to this file may cause incorrect behavior and will be lost if 
//      the code is regenerated.
//  </autogenerated>
// ------------------------------------------------------------------------------
using System;
using UnityEngine;
using DragonBones.Textures;
using DragonBones;

namespace DragonBones
{
	public class UnityBoneDisplay
	{
		public String Name;
		public float PivotX, PivotY;

		private bool _visible;

		private float[] _vertices;
		private float[] _verticesOrigin;
		private float[] _uvs;
		
		public float[] Vetices{
			get { return _vertices; }
			set {  _vertices = value;}
			
		}
		
		public float[] UVs{
			get { return _uvs; }
			set {  _uvs = value;}
			
		}

		public bool Visible{
			get{return _visible;}
			set{_visible = value;}
		}

		public void Update(Com.Viperstudio.Geom.Matrix matrix)
		{
			//TODO: vetex updating
            
			for(int i=0;i<8;i+=2)
			{
				_vertices[i] = _verticesOrigin[i] * matrix.A +  _verticesOrigin[i+1] * matrix.C + matrix.Tx ;
				_vertices[i + 1] = -(_verticesOrigin[i] * matrix.B + _verticesOrigin[i+1] * matrix.D + matrix.Ty) ;
               
            }
		

		}

		public void Dispose()
		{
		}

		public UnityBoneDisplay (TextureAtlas textureAtlas, TextureData textureData, float pivotX, float pivotY)
		{
			//TODO: build vetex and mesh
			PivotX = pivotX;
			PivotY = pivotY;
			_uvs = new float[8];
			_verticesOrigin = new float[8];
			_vertices = new float[8];

			_uvs [0] = textureData.region.x / (float)textureAtlas.Texture.width;
		    _uvs [1] = 1-textureData.region.y / (float)textureAtlas.Texture.height;
			_uvs [2] = (textureData.region.x + textureData.region.width)  / (float)textureAtlas.Texture.width;
			_uvs [3] = 1-textureData.region.y / (float)textureAtlas.Texture.height;
			_uvs [4] = (textureData.region.x +textureData.region.width)  / (float)textureAtlas.Texture.width;
		    _uvs [5] = 1-(textureData.region.y + textureData.region.height) / (float)textureAtlas.Texture.height;
			_uvs [6] = textureData.region.x / (float)textureAtlas.Texture.width;
		    _uvs [7] = 1-(textureData.region.y + textureData.region.height) / (float)textureAtlas.Texture.height;

		
			_vertices[0] = _verticesOrigin [0] = -pivotX;
		    _vertices[1] = _verticesOrigin [1] = -pivotY;
			_vertices[2] = _verticesOrigin [2] = textureData.region.width-pivotX;
		    _vertices[3] = _verticesOrigin [3] = -pivotY;
			_vertices[4] = _verticesOrigin [4] = textureData.region.width -pivotX ;
			_vertices[5] = _verticesOrigin [5] = textureData.region.height -pivotY;
			_vertices[6] = _verticesOrigin [6] = -pivotX;
			_vertices[7] = _verticesOrigin [7] = textureData.region.height -pivotY;

			//Debug.Log("added");

		}
	}
}
