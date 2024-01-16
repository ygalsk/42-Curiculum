t_texture_manager *load_textures(char **paths, size_t num_textures)
{
    t_texture_manager *manager;

    manager = (t_texture_manager *)malloc(sizeof(t_texture_manager));
    if (!manager)
        error();

    manager->num_textures = num_textures;
    manager->texture_paths = paths;

    manager->textures = (mlx_texture_t **)malloc(manager->num_textures * sizeof(mlx_texture_t *));
    manager->images = (mlx_image_t **)malloc(manager->num_textures * sizeof(mlx_image_t *));
    manager->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);

    if (!manager->mlx || !manager->textures || !manager->images)
        error();

    size_t i = 0;
    while (i < manager->num_textures)
    {
        manager->textures[i] = mlx_load_png(manager->texture_paths[i]);
        if (!manager->textures[i])
            error();

        manager->images[i] = mlx_texture_to_image(manager->mlx, manager->textures[i]);
        if (!manager->images[i])
            error();

        if (mlx_image_to_window(manager->mlx, manager->images[i], i * 50, i * 50) < 0)
            error();

        ++i;
    }

    return (manager);
}
