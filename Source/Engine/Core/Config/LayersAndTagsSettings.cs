// Copyright (c) 2012-2022 Wojciech Figat. All rights reserved.

using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.Marshalling;
using FlaxEngine;

namespace FlaxEditor.Content.Settings
{
    partial class LayersAndTagsSettings
    {
        /// <summary>
        /// The tag names.
        /// </summary>
        [EditorOrder(10), EditorDisplay("Tags", EditorDisplayAttribute.InlineStyle)]
        public List<string> Tags = new List<string>();

        /// <summary>
        /// The layers names.
        /// </summary>
        [EditorOrder(10), EditorDisplay("Layers", EditorDisplayAttribute.InlineStyle), Collection(ReadOnly = true)]
        public string[] Layers = new string[32];

        /// <summary>
        /// Gets the current tags collection.
        /// </summary>
        /// <returns>The tags collection.</returns>
        internal static string[] GetCurrentTags()
        {
            return GetCurrentTags(out int _);
        }

        /// <summary>
        /// Gets the current layer names (max 32 items but trims last empty items).
        /// </summary>
        /// <returns>The layers.</returns>
        public static string[] GetCurrentLayers()
        {
            return GetCurrentLayers(out int _);
        }

        [LibraryImport("FlaxEngine", EntryPoint = "FlaxEditor.Content.Settings.LayersAndTagsSettings::GetCurrentTags", StringMarshalling = StringMarshalling.Custom, StringMarshallingCustomType = typeof(FlaxEngine.StringMarshaller))]
        [return: MarshalUsing(typeof(FlaxEngine.ArrayMarshaller<,>), CountElementName = "tagCount")]
        internal static partial string[] GetCurrentTags(out int tagCount);

        [LibraryImport("FlaxEngine", EntryPoint = "FlaxEditor.Content.Settings.LayersAndTagsSettings::GetCurrentLayers", StringMarshalling = StringMarshalling.Custom, StringMarshallingCustomType = typeof(FlaxEngine.StringMarshaller))]
        [return: MarshalUsing(typeof(FlaxEngine.ArrayMarshaller<,>), CountElementName = "layerCount")]
        internal static partial string[] GetCurrentLayers(out int layerCount);
    }
}
